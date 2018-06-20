#include <stdio.h>
#include <stdlib.h>

#define MAX_VEX_NUM 20
#define INFINITY -1
// 顶点访问标志类型声明 
typedef enum {UNVISITED=0, VISITED=1} visit_t;
// 采用邻接矩阵表示法的图类型定义 
// 这里假设：顶点的信息为 unsigned int类型；边的信息 也为 unsigned int类型， 1表示有边， 0 表示无边。 
typedef struct
{
	unsigned int vertex[MAX_VEX_NUM];
	unsigned int arcs[MAX_VEX_NUM][MAX_VEX_NUM];
	int vex_num, arc_num;
} m_graph_t;

// 输出图的邻接矩阵 
void print_graph(m_graph_t g)
{
	int i, j;

	for (i=0; i<g.vex_num; i++) {
		for (j=0; j<g.vex_num; j++)
			printf("%3d", g.arcs[i][j]);
		printf("\n");
	}
}

// 求图g中顶点v的第一个邻接点，若存在，则返回该邻接点在图中的位置（>=0）；否则返回-1。 
int first_adj(m_graph_t g, int v)
{
	int w = 0;
	while ((w<g.vex_num) && (g.arcs[v][w]==0)) w++;
	if (w==g.vex_num) return -1;
	else return w;
}

// 求图g中顶点v的相对于邻接点w的下一个邻接点，若存在，则返回该邻接点在图中的位置（>=0）；否则返回-1。 
int next_adj(m_graph_t g, int v, int w)
{
	int u = w+1;
	while ((u<g.vex_num) && (g.arcs[v][u]==0)) u++;
	if (u==g.vex_num) return -1;
	else return u;
}

// 深度优先搜索遍历 
visit_t visited[MAX_VEX_NUM];
void depth_first(m_graph_t g, int v)
{
	int w;

	visited[v] = VISITED;
	printf("%3d",g.vertex[v]);
	for (w=first_adj(g, v); w >= 0; w=next_adj(g, v, w)) 
		if (!visited[w]) depth_first(g, w);
}
void depth_first_traverse(m_graph_t g)
{
	int v;
	
	for (v=0;v<g.vex_num;v++) visited[v] = UNVISITED;
	for (v=0;v<g.vex_num;v++) 
		if (!visited[v]) depth_first(g, v);
}


// 队列的存储结构及基本操作 
typedef unsigned int queue_elem_t;
// typedef int queue_elem_t;
typedef enum {EMPTY, FULL, READY} status_t;
typedef struct
{
     queue_elem_t *data;
     int front;
     int rear;
     int queue_len;
     status_t status;
} queue;
typedef queue *queue_t;

queue_t init_queue(int len)
{
     queue_t q = (queue_t)malloc(sizeof(queue));
     if (!q) {
          printf("Heap full.\n");
          exit(-1);
     }
     q->data = (queue_elem_t *)malloc(sizeof(queue_elem_t) * len);
     if (!q->data) {
          printf("Heap full.\n");
          exit(-1);
     }
     q->front = q->rear = 0;
     q->queue_len = len;
     q->status = EMPTY;

     return q;
}

queue_t destroy_queue(queue_t q)
{
     if (q) {
          free(q->data);
          free(q);
     }
	
     return NULL;
}

int is_empty(queue_t q)
{
     return (q->status==EMPTY);
}

void enqueue(queue_t q, queue_elem_t data)
{
     if (!q) {
          printf("You need init queue before using it.\n");
          exit(-1);
     }
     if (q->status != FULL) {
          q->data[q->rear] = data;
          q->rear = (q->rear + 1) % q->queue_len;
          if (q->rear == q->front)
               q->status = FULL;
          else
               q->status = READY;
     }
	
}

queue_elem_t dequeue(queue_t q)
{
     queue_elem_t data;
	
     if (!q) {
          printf("You need init queue before using it.\n");
          exit(-1);
     }
     if (q->status != EMPTY) {
          data = q->data[q->front];
          q->front = (q->front + 1) % q->queue_len;
          if (q->front == q->rear)
               q->status = EMPTY;
          else
               q->status = READY;
     }
	
     return data;
}

queue_elem_t get_front(queue_t q)
{
     return q->data[q->front];
}

void visit_front(queue_t q, void (*do_front)(queue_elem_t *))
{
     if (q->status != EMPTY) 
          do_front(&(q->data[q->front]));
}

void traverse_queue(queue_t q, void (*do_data)(queue_elem_t *))
{
     int front;
     if (q->status != EMPTY) {
          front = q->front;
          do {
               do_data(&(q->data[front]));
               front = (front + 1) % q->queue_len;
          } while (front != q->rear);
     }
}

// 广度优先搜索遍历 
void breadth_first_traverse(m_graph_t g)
{
     visit_t visited[MAX_VEX_NUM];
     int u, v, w;
     queue_t q = init_queue(g.vex_num);
     
     for (v=0;v<g.vex_num;v++) visited[v] = UNVISITED;
     for (v=0;v<g.vex_num;v++) 
          	if (!visited[v]) {
               	visited[v] = VISITED;
               	printf("%3d", g.vertex[v]);
               	enqueue(q, v);
				while (!is_empty(q)) {
               		u = dequeue(q);
               		for (w=first_adj(g, u); w!=-1; w=next_adj(g, u, w))
                    	if (!visited[v]) {
                        	visited[v] = VISITED;
                         	printf("%3d", g.vertex[v]);
                         	enqueue(q, v);
                    	} //if 
          		} // while
     		} // if
     destroy_queue(q);
}

// 顶点定位函数 
int LocateVex(m_graph_t *g, unsigned int v){
	int i;
	for (i = 0; i <= g->vex_num; ++i){
		if(g->vertex[i]==v) return i;
	} 
	return -1;
}

// 无向图构造函数 
void create_UDG(m_graph_t *g)
{ //采用数组（邻接矩阵）表示法，构造无向网g。
	int i, j, k;
	unsigned int v1, v2; 
	printf("请输入图的顶点数和边数：");
	scanf("%d,%d", &g->vex_num, &g->arc_num); 
	printf("请输入%d个顶点的信息：\n", g->vex_num);
  	for (i = 0; i < g->vex_num; ++i) scanf("%d", &g->vertex[i]); //构造顶点向量
  	for (i = 0; i < g->vex_num; ++i) //初始化邻接矩阵
    	for (j = 0; j < g->vex_num; ++j) g->arcs[i][j] = 0;
 	printf("请输入%d条边的信息：", g->arc_num);
   	for (k = 0; k < g->arc_num; ++k) { //构造邻接矩阵
		printf("\n第%d条边（输入该边所依附的两个顶点）：", k+1);
    	scanf("%d,%d",&v1, &v2);	//输入一条边依附的顶点
    	i = LocateVex(g, v1); j = LocateVex(g, v2);	//确定v1和v2在G中位置
    	g->arcs[i][j] = 1;	
    	g->arcs[j][i] = g->arcs[i][j]; //置<v1, v2>的对称边<v2, v1>
  	}
  	return;
}
	
/*

       1
      / \
     /   \
    2	  3
   / \   / \
  4   5 6---7 
   \ /
    8
     
*/

int main()
{
/*
	m_graph_t g = {
		{1, 2, 3, 4, 5, 6, 7, 8}, // vertex
		{{  0,  1,  1,  0,  0,  0,  0,  0}, // arcs
		 {  1,  0,  0,  1,  1,  0,  0,  0},
		 {  1,  0,  0,  0,  0,  1,  1,  0},
		 {  0,  1,  0,  0,  0,  0,  0,  1},
		 {  0,  1,  0,  0,  0,  0,  0,  1},
		 {  0,  0,  1,  0,  0,  0,  1,  0},
		 {  0,  0,  1,  0,  0,  1,  0,  0},
		 {  0,  0,  0,  1,  1,  0,  0,  0}},
		8, // vex_num
		9 // arc_num
	};
*/
	m_graph_t g;

	create_UDG(&g);  // 调用创建无向图的函数 

	print_graph(g); printf("\n");
	depth_first_traverse(g); printf("\n");
	breadth_first_traverse(g); printf("\n");

	return 0;
}
