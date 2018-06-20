#include <stdio.h>
#include <stdlib.h>

#define MAX_VEX_NUM 20
#define INFINITY -1
// ������ʱ�־�������� 
typedef enum {UNVISITED=0, VISITED=1} visit_t;
// �����ڽӾ����ʾ����ͼ���Ͷ��� 
// ������裺�������ϢΪ unsigned int���ͣ��ߵ���Ϣ ҲΪ unsigned int���ͣ� 1��ʾ�бߣ� 0 ��ʾ�ޱߡ� 
typedef struct
{
	unsigned int vertex[MAX_VEX_NUM];
	unsigned int arcs[MAX_VEX_NUM][MAX_VEX_NUM];
	int vex_num, arc_num;
} m_graph_t;

// ���ͼ���ڽӾ��� 
void print_graph(m_graph_t g)
{
	int i, j;

	for (i=0; i<g.vex_num; i++) {
		for (j=0; j<g.vex_num; j++)
			printf("%3d", g.arcs[i][j]);
		printf("\n");
	}
}

// ��ͼg�ж���v�ĵ�һ���ڽӵ㣬�����ڣ��򷵻ظ��ڽӵ���ͼ�е�λ�ã�>=0�������򷵻�-1�� 
int first_adj(m_graph_t g, int v)
{
	int w = 0;
	while ((w<g.vex_num) && (g.arcs[v][w]==0)) w++;
	if (w==g.vex_num) return -1;
	else return w;
}

// ��ͼg�ж���v��������ڽӵ�w����һ���ڽӵ㣬�����ڣ��򷵻ظ��ڽӵ���ͼ�е�λ�ã�>=0�������򷵻�-1�� 
int next_adj(m_graph_t g, int v, int w)
{
	int u = w+1;
	while ((u<g.vex_num) && (g.arcs[v][u]==0)) u++;
	if (u==g.vex_num) return -1;
	else return u;
}

// ��������������� 
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


// ���еĴ洢�ṹ���������� 
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

// ��������������� 
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

// ���㶨λ���� 
int LocateVex(m_graph_t *g, unsigned int v){
	int i;
	for (i = 0; i <= g->vex_num; ++i){
		if(g->vertex[i]==v) return i;
	} 
	return -1;
}

// ����ͼ���캯�� 
void create_UDG(m_graph_t *g)
{ //�������飨�ڽӾ��󣩱�ʾ��������������g��
	int i, j, k;
	unsigned int v1, v2; 
	printf("������ͼ�Ķ������ͱ�����");
	scanf("%d,%d", &g->vex_num, &g->arc_num); 
	printf("������%d���������Ϣ��\n", g->vex_num);
  	for (i = 0; i < g->vex_num; ++i) scanf("%d", &g->vertex[i]); //���춥������
  	for (i = 0; i < g->vex_num; ++i) //��ʼ���ڽӾ���
    	for (j = 0; j < g->vex_num; ++j) g->arcs[i][j] = 0;
 	printf("������%d���ߵ���Ϣ��", g->arc_num);
   	for (k = 0; k < g->arc_num; ++k) { //�����ڽӾ���
		printf("\n��%d���ߣ�����ñ����������������㣩��", k+1);
    	scanf("%d,%d",&v1, &v2);	//����һ���������Ķ���
    	i = LocateVex(g, v1); j = LocateVex(g, v2);	//ȷ��v1��v2��G��λ��
    	g->arcs[i][j] = 1;	
    	g->arcs[j][i] = g->arcs[i][j]; //��<v1, v2>�ĶԳƱ�<v2, v1>
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

	create_UDG(&g);  // ���ô�������ͼ�ĺ��� 

	print_graph(g); printf("\n");
	depth_first_traverse(g); printf("\n");
	breadth_first_traverse(g); printf("\n");

	return 0;
}
