#include<stdio.h>
#include<stdlib.h>
//�������״̬��
#define TRUE 1
#define FALSE 0 
#define OK 1 
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬��
typedef int Status;

#define ElemType int//����Ԫ�ص����� 
#define LIST_INIT_SIZE 10//���Ա�洢�ռ�ĳ�ʼ������
#define LIST_INCREMENT 2//���Ա�洢�ռ�ķ�������
typedef struct{
	ElemType *elem;//���Ա�Ļ���ַ 
	int length;//���Ա�ĵ�ǰ����
	int listsize;//���Ա�ǰ����Ĵ洢�ռ��С 
}SqList;

/*1.
�������������һ���յ����Ա�L��*/ 
Status InitList_Sq(SqList &L){//���� 
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));//˳���Ļ���ַ 
	if(!L.elem){//�жϷ��䶯̬�洢�ռ��Ƿ�ɹ� 
		exit(OVERFLOW);//������ʧ���������Ӧ�ĺ���״̬����� 
	}
	L.length = 0;//˳���Ϊ�ձ�ʱ���䵱ǰ����Ϊ0 
	L.listsize = LIST_INIT_SIZE;//˳���ǰ����Ķ�̬�洢�ռ��С 
	return OK;//�����ɹ� 
}

/*2.
��ʼ���������Ա�L�Ѵ��ڡ� 
����������������Ա�L��*/ 
Status DestroyList_Sq(SqList &L){//���� 
	free(L.elem);//�ͷ�L.elem��ָ�Ĵ洢�ռ� 
	L.elem = NULL;//��˳���Ļ���ַ��ΪNULL����L.elem����ָ���κδ洢��Ԫ 
	L.length = 0;//��˳���ĵ�ǰ������Ϊ0 
	L.listsize = 0;//��˳���ǰ����Ĵ洢�ռ��С��Ϊ0 
	return OK;//�����ɹ� 
}

/*3.
��ʼ���������Ա�L�Ѵ��ڡ� 
�����������L����Ϊ�ձ�*/
Status ClearList_Sq(SqList &L){//���� 
	L.length = 0;//��˳���ĵ�ǰ������Ϊ0 
	return OK;//�����ɹ� 
} 

/*4.
��ʼ���������Ա�L�Ѵ��ڡ� 
�����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE��*/
Status ListEmpty_Sq(SqList L){
	if(L.length == 0){//�ж�˳���ĵ�ǰ�����Ƿ�Ϊ0 
		return TRUE;//��˳���ĵ�ǰ����Ϊ0���򷵻�TRUE 
	}else{
		return FALSE;//��˳���ĵ�ǰ���Ȳ�Ϊ0���򷵻�FALSE 
	}
} 

/*5. 
��ʼ���������Ա�L�Ѵ��ڡ� 
�������������L������Ԫ�ظ�����*/
Status ListLength_Sq(SqList L){
	return L.length;//����˳���ĵ�ǰ���� 
} 

/*6.
��ʼ���������Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)�� 
�����������e����L�е�i������Ԫ�ص�ֵ��*/ 
Status GetElem_Sq(SqList L, int i, ElemType &e){//���� 
	if((i < 1) || (i > L.length)){//�ж�i�Ƿ��ںϷ���Χ�ڣ���1<=i<=L.length 
		return ERROR;//��i���ںϷ���Χ�ڣ��򷵻���Ӧ�ĺ���״̬����� 
	}
	e = *(L.elem + i - 1);//����ַ(L.elem+i-1)��ָ�洢�ռ��е�ֵ��ֵ��e
	return OK;//�����ɹ� 
} 

/*7.
��ʼ���������Ա��Ѵ��ڣ�compare()������Ԫ���ж������� 
�������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0��*/ 
Status LocateElem_Sq(SqList L, ElemType e, Status (* compare)(ElemType, ElemType)){
	int i = 1;//���ͱ���i�ĳ�ֵΪ1����ʾ��һ��Ԫ�ص�λ��
	ElemType *p = L.elem;//ElemType����ָ��p�ĳ�ֵΪ˳���Ļ���ַ����ʾ��һ��Ԫ�صĴ洢λ�� 
	while((i <= L.length) && (!compare(*(p++), e))){//��i�ںϷ���Χ����δ�ҵ������ϵ������Ԫ�أ������ѭ�� 
		i++;//��������Ԫ�ص�λ�� 
	}
	if(i <= L.length){//�ж��Ƿ��ҵ������ϵ������Ԫ�� 
		return i;//���ҵ����򷵻ظ�����Ԫ�ص�λ�� 
	}else{
		return 0;//��δ�ҵ����򷵻�0 
	}
}
//����Ԫ���ж��������ж���������Ԫ���Ƿ����(Ҳ���Զ���������ϵ)�� 
Status Equal(ElemType e1, ElemType e2){
	if(e1 == e2){//�ж�e1��e2�Ƿ���� 
		return TRUE;//����ȣ��򷵻�TRUE 
	}else{
		return FALSE;//������ȣ��򷵻�FALSE 
	}
}

/*8.
��ʼ���������Ա�L�Ѵ��ڡ� 
�����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣*/ 
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType &pre_e){//���� 
	int i = 2;//���ͱ���i�ĳ�ֵΪ2����ʾ�ڶ���Ԫ�ص�λ��
	ElemType *p = L.elem + 1;//ElemType����ָ��p�ĳ�ֵΪ(˳���Ļ���ַ+1)����ʾ�ڶ���Ԫ�صĴ洢λ�� 
	while((i <= L.length) && (*p != cur_e)){//��i�ںϷ���Χ���ҵ�ǰָ��p��ָ�洢��Ԫ��ֵ������cur_e�������ѭ�� 
		p++;//����ָ��p��ֵ��ʹָ��pָ����һ������Ԫ�� 
		i++;//��������Ԫ�ص�λ�� 
	}
	if(i <= L.length){//�ж��Ƿ��ҵ���cur_e��ȵ�����Ԫ�� 
		pre_e = *(--p);//����ǰָ��p��ָ�洢��Ԫ��ǰһ���洢��Ԫ�е�ֵ����pre_e 
		return OK;//�����ɹ� 
	}else{
		return ERROR;//����ʧ�� 
	}
}

/*9.
��ʼ���������Ա�L�Ѵ��ڡ� 
�����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��塣*/ 
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType &next_e){
	int i = 1;//���ͱ���i�ĳ�ֵΪ1����ʾ��һ��Ԫ�ص�λ��
	ElemType *p = L.elem;//ElemType����ָ��p�ĳ�ֵΪ˳���Ļ���ַ����ʾ��һ��Ԫ�صĴ洢λ��
	while((i < L.length) && (*p != cur_e)){//��i�ںϷ���Χ���ҵ�ǰָ��p��ָ�洢��Ԫ��ֵ������cur_e�������ѭ�� 
		p++;//����ָ��p��ֵ��ʹָ��pָ����һ������Ԫ�� 
		i++;//��������Ԫ�ص�λ�� 
	} 
	if(i == L.length){//�ж��Ƿ��ҵ���cur_e��ȵ�����Ԫ�� 
		return ERROR;//����ʧ�� 
	}else{
		next_e = *(++p);//����ǰָ��p��ָ�洢��Ԫ�ĺ�һ���洢��Ԫ��ֵ����next_e 
		return OK;//�����ɹ� 
	}
}

/*10.
��ʼ���������Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)+1�� 
�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1��*/ 
Status ListInsert_Sq(SqList &L, int i, ElemType e){//���� 
	//newbase��ʾ���·��䶯̬�洢�ռ��˳���Ļ���ַ��
	//q��ʾ��Ҫ����ƶ�������Ԫ�����е��׵�ַ��
	//p��ʾ��Ҫ����ƶ�������Ԫ�����е�β��ַ�� 
	ElemType *newbase, *q, *p; 
	if((i < 1) || (i > (L.length + 1))){//�ж�i�Ƿ��ںϷ���Χ�ڣ���1<=i<=L.length+1
		return ERROR;//��i���ںϷ���Χ�ڣ��򷵻���Ӧ�ĺ���״̬�����
	}
	if(L.length == L.listsize){//�жϵ�ǰ��̬�洢�ռ��Ƿ����� 
		//����ǰ��̬�洢�ռ�����������Ҫ�������ӷ��䶯̬�洢�ռ� 
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LIST_INCREMENT)*sizeof(ElemType)); 
		if(!newbase){//�ж����·��䶯̬�洢�ռ��Ƿ�ɹ� 
			exit(OVERFLOW);//������ʧ���������Ӧ�ĺ���״̬����� 
		}
		L.elem = newbase;//���·��䶯̬�洢�ռ��˳���Ļ���ַ
		L.listsize += LIST_INCREMENT;//���·��䶯̬�洢�ռ��˳���Ķ�̬�洢�ռ��С 
	}
	q = L.elem + i - 1;//����λ��i��Ӧ�洢��Ԫ�ĵ�ַ 
	for(p = (L.elem + L.length - 1); p >= q; p--){//ָ��p�ĳ�ֵΪ����Ԫ������ƶ�ǰ˳����β��ַ 
		*(p+1) = *p;//����λ�ü���֮�������Ԫ������ƶ� 
	}
	*q = e;//����Ҫ�����ֵ���ڲ���λ�ö�Ӧ�Ĵ洢��Ԫ�� 
	L.length++;//����˳���ĵ�ǰ���� 
	return OK;//�����ɹ� 
}

/*11.
��ʼ���������Ա�L�Ѵ����ҷǿգ�1<=i<=ListLength(L)�� 
���������ɾ��L�ĵ�i��Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1��*/ 
Status ListDelete_Sq(SqList &L, int i, ElemType &e){
	//p��ʾɾ��λ������Ӧ�洢��Ԫ�ĵ�ַ��
	//q��ʾ����Ԫ����ǰ�ƶ�ǰ˳����β��ַ 
	ElemType *p, *q;
	if((i < 1) || (i > L.length)){//�ж�i�Ƿ��ںϷ���Χ�ڣ���1<=i<=L.length
		return ERROR;//��i���ںϷ���Χ�ڣ��򷵻���Ӧ�ĺ���״̬�����
	}
	p = L.elem + i - 1;//ɾ��λ��i��Ӧ�洢��Ԫ�ĵ�ַ 
	e = *p;//��ɾ��λ�ö�Ӧ�洢��Ԫ��ֵ����e 
	q = L.elem + L.length - 1;//����Ԫ���ƶ�ǰ˳����β��ַ 
	for(p++; p <= q; p++){//ָ��p�ĳ�ֵΪ��Ҫ��ǰ�ƶ�������Ԫ�����е��׵�ַ 
		*(p-1) = *p;//ɾ��λ��֮�������Ԫ����ǰ�ƶ� 
	} 
	L.length--;//�Լ�˳���ĵ�ǰ���� 
	return OK;//�����ɹ� 
}

/*12.
��ʼ���������Ա�L�Ѵ��ڡ�
������������ζ�L��ÿ������Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ�ܡ�*/ 
Status ListTraverse_Sq(SqList L, void (* visit)(ElemType&)){//���� 
	ElemType *p = L.elem;//p��ʾ˳���Ļ���ַ
	int i;//��ʾ˳���������Ԫ�ص�λ��
	for(i = 1; i <= L.length; i++){//��λ��Ϊ�������α���˳����е�����Ԫ�� 
		visit(*(p++));//��˳����е�ÿ������Ԫ�ص���visit()���� 
	} 
	printf("\n");//������� 
	return OK;//�����ɹ� 
}
//��˳����е���������Ԫ������1 
void auto_increment(ElemType &e){
	e++;
}
//���˳����е���������Ԫ�� 
void print(ElemType &e){
	printf("%d ", e);
}

int main(){
	//����˳���L
	SqList L; 
	
	//����һ���յ�˳���L 
	InitList_Sq(L); 
	
	//��ʼ��˳���L
	int n = 10;//��Ҫ��˳���L�в���10������Ԫ�� 
	for(int i = 1; i <= n; i++){//i��ʾ˳���L������Ԫ�ص�λ�� 
		ListInsert_Sq(L, i, i);//��˳���L�в�������Ԫ�� 
	} 
	
	//���˳���L�е���������Ԫ��
	printf("˳���L�е���������Ԫ��Ϊ:\n");
	ListTraverse_Sq(L, print);//�������˳���L�е�����Ԫ�� 
	
	//��˳���L�е���������Ԫ������1�����
	ListTraverse_Sq(L, auto_increment);//���ν�˳���L�е�����Ԫ������1 
	printf("����1��,˳���L�е���������Ԫ��Ϊ:\n");
	ListTraverse_Sq(L, print);
	
	//�ж�˳���L�Ƿ�Ϊ�ձ�
	printf("\n�����1,��˳���LΪ�ձ�;�����0,��˳���L��Ϊ�ձ�:\n%d\n", ListEmpty_Sq(L)); 
	
	//���˳���L�е�����Ԫ�ظ��� 
	printf("\n˳���L�е�����Ԫ�ظ���Ϊ:\n%d\n", ListLength_Sq(L));
	
	//��ȡ˳���L�е�i������Ԫ��
	int e0 = 0, i = 5;//i��ʾ����Ԫ�ص�λ�� 
	GetElem_Sq(L, i, e0);//����i������Ԫ�ش���e0�� 
	printf("\n˳���L�е�%d������Ԫ��Ϊ:\n%d\n", i, e0); 
	
	//���˳���L����ָ������Ԫ������һ����ϵ������Ԫ�ص�λ��(��ʵ����Ϊ��ȹ�ϵ)
	int e1 = 4;//e1Ϊָ��������Ԫ��
	printf("\n��%d������ȹ�ϵ������Ԫ�ص�λ��Ϊ:\n%d\n", e1, LocateElem_Sq(L, e1, Equal));//����˳���L����e������ȹ�ϵ������Ԫ�ص�λ��
	 
	//���ָ������Ԫ�ص�ǰ��
	int e2 = 5;//e2Ϊָ��������Ԫ��
	int pre_e2 = 0;//pre_e2���ڴ洢e2��ǰ��
	PriorElem_Sq(L, e2, pre_e2);//��ȡe2��ǰ�����������pre_e2��
	printf("\n%d��ǰ��Ϊ:\n%d\n", e2, pre_e2); 
	
	//���ָ������Ԫ�صĺ��
	int e3 = 4;//e3Ϊָ��������Ԫ��
	int next_e3 = 0;//next_e3���ڴ洢e3�ĺ��
	NextElem_Sq(L, e3, next_e3);//��ȡe3�ĺ�̲��������next_e3��
	printf("\n%d�ĺ��Ϊ:\n%d\n", e3, next_e3);
	
	//��˳����в���ָ������Ԫ��
	int i1 = 4;//i1Ϊ����λ�õ�λ��
	int e4 = 25;//e4ΪҪ�����ָ������Ԫ��
	printf("\n��������Ԫ��ǰ,˳���L�ĳ��Ⱥʹ洢�ռ��С�ֱ�Ϊ:\n%d��%d", L.length, L.listsize);
	ListInsert_Sq(L, i1, e4);//��˳���L�в���e4
	printf("\n��������Ԫ�غ�,˳���L�ĳ��Ⱥʹ洢�ռ��С�ֱ�Ϊ:\n%d��%d\n", L.length, L.listsize);
	printf("��������Ԫ�غ�,˳���L����������Ԫ��Ϊ:\n");
	ListTraverse_Sq(L, print);
	
	//��˳�����ɾ��ָ������Ԫ��
	int i2 = 3;//i2Ϊɾ��λ�õ�λ��
	int e5 = 0;//e5���ڴ洢��ɾ��������Ԫ�� 
	printf("\nɾ������Ԫ��ǰ,˳���L�ĳ��Ⱥʹ洢�ռ��С�ֱ�Ϊ:\n%d��%d", L.length, L.listsize);
	ListDelete_Sq(L, i2, e5);//ɾ��˳���L��λ��Ϊi2������Ԫ�ز��������e5�� 
	printf("\nɾ������Ԫ�غ�,˳���L�ĳ��Ⱥʹ洢�ռ��С�ֱ�Ϊ:\n%d��%d\n", L.length, L.listsize);
	printf("ɾ��������Ԫ��Ϊ:\n%d\n", e5);
	printf("ɾ������Ԫ�غ�,˳���L����������Ԫ��Ϊ:\n");
	ListTraverse_Sq(L, print);
	
	//��˳�������Ϊ�ձ�
	printf("\n(˳���L����Ϊ�ձ�ǰ)�����1,��˳���LΪ�ձ�;�����0,��˳���L��Ϊ�ձ�:\n%d", ListEmpty_Sq(L)); 
	ClearList_Sq(L);//��˳���LֵΪ�ձ�
	printf("\n(˳���L����Ϊ�ձ��)�����1,��˳���LΪ�ձ�;�����0,��˳���L��Ϊ�ձ�:\n%d\n", ListEmpty_Sq(L));

	//����˳��� 
	printf("\n(����˳���Lǰ)˳���L�Ļ���ַ�����Ⱥʹ洢�ռ��С�ֱ�Ϊ:\n%d��%d��%d", L.elem, L.length, L.listsize);
	DestroyList_Sq(L);//����˳���L
	printf("\n(����˳���L��)˳���L�Ļ���ַ�����Ⱥʹ洢�ռ��С�ֱ�Ϊ:\n%d��%d��%d\n", L.elem, L.length, L.listsize);
	
	return 0;
} 
