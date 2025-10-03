#include<stdio.h>
#include<stdlib.h>
//函数结果状态码
#define TRUE 1
#define FALSE 0 
#define OK 1 
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status是函数的类型，其值是函数结果状态码
typedef int Status;

#define ElemType int//数据元素的类型 
#define LIST_INIT_SIZE 10//线性表存储空间的初始分配量
#define LIST_INCREMENT 2//线性表存储空间的分配增量
typedef struct{
	ElemType *elem;//线性表的基地址 
	int length;//线性表的当前长度
	int listsize;//线性表当前分配的存储空间大小 
}SqList;

/*1.
操作结果：构造一个空的线性表L。*/ 
Status InitList_Sq(SqList &L){//引用 
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));//顺序表的基地址 
	if(!L.elem){//判断分配动态存储空间是否成功 
		exit(OVERFLOW);//若分配失败则输出相应的函数状态结果码 
	}
	L.length = 0;//顺序表为空表时，其当前长度为0 
	L.listsize = LIST_INIT_SIZE;//顺序表当前分配的动态存储空间大小 
	return OK;//操作成功 
}

/*2.
初始条件：线性表L已存在。 
操作结果：销毁线性表L。*/ 
Status DestroyList_Sq(SqList &L){//引用 
	free(L.elem);//释放L.elem所指的存储空间 
	L.elem = NULL;//将顺序表的基地址置为NULL，即L.elem不再指向任何存储单元 
	L.length = 0;//将顺序表的当前长度置为0 
	L.listsize = 0;//将顺序表当前分配的存储空间大小置为0 
	return OK;//操作成功 
}

/*3.
初始条件：线性表L已存在。 
操作结果：将L重置为空表。*/
Status ClearList_Sq(SqList &L){//引用 
	L.length = 0;//将顺序表的当前长度置为0 
	return OK;//操作成功 
} 

/*4.
初始条件：线性表L已存在。 
操作结果：若L为空表，则返回TRUE，否则返回FALSE。*/
Status ListEmpty_Sq(SqList L){
	if(L.length == 0){//判断顺序表的当前长度是否为0 
		return TRUE;//若顺序表的当前长度为0，则返回TRUE 
	}else{
		return FALSE;//若顺序表的当前长度不为0，则返回FALSE 
	}
} 

/*5. 
初始条件：线性表L已存在。 
操作结果：返回L中数据元素个数。*/
Status ListLength_Sq(SqList L){
	return L.length;//返回顺序表的当前长度 
} 

/*6.
初始条件：线性表L已存在，1<=i<=ListLength(L)。 
操作结果：用e返回L中第i个数据元素的值。*/ 
Status GetElem_Sq(SqList L, int i, ElemType &e){//引用 
	if((i < 1) || (i > L.length)){//判断i是否在合法范围内，即1<=i<=L.length 
		return ERROR;//若i不在合法范围内，则返回相应的函数状态结果码 
	}
	e = *(L.elem + i - 1);//将地址(L.elem+i-1)所指存储空间中的值赋值给e
	return OK;//操作成功 
} 

/*7.
初始条件：线性表已存在，compare()是数据元素判定函数。 
操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0。*/ 
Status LocateElem_Sq(SqList L, ElemType e, Status (* compare)(ElemType, ElemType)){
	int i = 1;//整型变量i的初值为1，表示第一个元素的位序
	ElemType *p = L.elem;//ElemType类型指针p的初值为顺序表的基地址，表示第一个元素的存储位置 
	while((i <= L.length) && (!compare(*(p++), e))){//若i在合法范围内且未找到满足关系的数据元素，则继续循环 
		i++;//自增数据元素的位序 
	}
	if(i <= L.length){//判断是否找到满足关系的数据元素 
		return i;//若找到，则返回该数据元素的位序 
	}else{
		return 0;//若未找到，则返回0 
	}
}
//数据元素判定函数，判断两个数据元素是否相等(也可自定义其他关系)。 
Status Equal(ElemType e1, ElemType e2){
	if(e1 == e2){//判断e1和e2是否相等 
		return TRUE;//若相等，则返回TRUE 
	}else{
		return FALSE;//若不相等，则返回FALSE 
	}
}

/*8.
初始条件：线性表L已存在。 
操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义。*/ 
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType &pre_e){//引用 
	int i = 2;//整型变量i的初值为2，表示第二个元素的位序
	ElemType *p = L.elem + 1;//ElemType类型指针p的初值为(顺序表的基地址+1)，表示第二个元素的存储位置 
	while((i <= L.length) && (*p != cur_e)){//若i在合法范围内且当前指针p所指存储单元的值不等于cur_e，则继续循环 
		p++;//自增指针p的值，使指针p指向下一个数据元素 
		i++;//自增数据元素的位序 
	}
	if(i <= L.length){//判断是否找到与cur_e相等的数据元素 
		pre_e = *(--p);//将当前指针p所指存储单元的前一个存储单元中的值赋给pre_e 
		return OK;//操作成功 
	}else{
		return ERROR;//操作失败 
	}
}

/*9.
初始条件：线性表L已存在。 
操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义。*/ 
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType &next_e){
	int i = 1;//整型变量i的初值为1，表示第一个元素的位序
	ElemType *p = L.elem;//ElemType类型指针p的初值为顺序表的基地址，表示第一个元素的存储位置
	while((i < L.length) && (*p != cur_e)){//若i在合法范围内且当前指针p所指存储单元的值不等于cur_e，则继续循环 
		p++;//自增指针p的值，使指针p指向下一个数据元素 
		i++;//自增数据元素的位序 
	} 
	if(i == L.length){//判断是否找到与cur_e相等的数据元素 
		return ERROR;//操作失败 
	}else{
		next_e = *(++p);//将当前指针p所指存储单元的后一个存储单元的值赋给next_e 
		return OK;//操作成功 
	}
}

/*10.
初始条件：线性表L已存在，1<=i<=ListLength(L)+1。 
操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1。*/ 
Status ListInsert_Sq(SqList &L, int i, ElemType e){//引用 
	//newbase表示重新分配动态存储空间后，顺序表的基地址；
	//q表示需要向后移动的数据元素序列的首地址；
	//p表示需要向后移动的数据元素序列的尾地址。 
	ElemType *newbase, *q, *p; 
	if((i < 1) || (i > (L.length + 1))){//判断i是否在合法范围内，即1<=i<=L.length+1
		return ERROR;//若i不在合法范围内，则返回相应的函数状态结果码
	}
	if(L.length == L.listsize){//判断当前动态存储空间是否已满 
		//若当前动态存储空间已满，则需要重新增加分配动态存储空间 
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LIST_INCREMENT)*sizeof(ElemType)); 
		if(!newbase){//判断重新分配动态存储空间是否成功 
			exit(OVERFLOW);//若分配失败则输出相应的函数状态结果码 
		}
		L.elem = newbase;//重新分配动态存储空间后，顺序表的基地址
		L.listsize += LIST_INCREMENT;//重新分配动态存储空间后，顺序表的动态存储空间大小 
	}
	q = L.elem + i - 1;//插入位序i对应存储单元的地址 
	for(p = (L.elem + L.length - 1); p >= q; p--){//指针p的初值为数据元素向后移动前顺序表的尾地址 
		*(p+1) = *p;//插入位置及其之后的数据元素向后移动 
	}
	*q = e;//将需要插入的值存于插入位置对应的存储单元中 
	L.length++;//自增顺序表的当前长度 
	return OK;//操作成功 
}

/*11.
初始条件：线性表L已存在且非空，1<=i<=ListLength(L)。 
操作结果：删除L的第i个元素，并用e返回其值，L的长度减1。*/ 
Status ListDelete_Sq(SqList &L, int i, ElemType &e){
	//p表示删除位置所对应存储单元的地址；
	//q表示数据元素向前移动前顺序表的尾地址 
	ElemType *p, *q;
	if((i < 1) || (i > L.length)){//判断i是否在合法范围内，即1<=i<=L.length
		return ERROR;//若i不在合法范围内，则返回相应的函数状态结果码
	}
	p = L.elem + i - 1;//删除位序i对应存储单元的地址 
	e = *p;//将删除位置对应存储单元的值赋给e 
	q = L.elem + L.length - 1;//数据元素移动前顺序表的尾地址 
	for(p++; p <= q; p++){//指针p的初值为需要向前移动的数据元素序列的首地址 
		*(p-1) = *p;//删除位置之后的数据元素向前移动 
	} 
	L.length--;//自减顺序表的当前长度 
	return OK;//操作成功 
}

/*12.
初始条件：线性表L已存在。
操作结果：依次对L的每个数据元素调用函数visit()。一旦visit()失败，则操作失败。*/ 
Status ListTraverse_Sq(SqList L, void (* visit)(ElemType&)){//引用 
	ElemType *p = L.elem;//p表示顺序表的基地址
	int i;//表示顺序表中数据元素的位序
	for(i = 1; i <= L.length; i++){//以位序为索引依次遍历顺序表中的数据元素 
		visit(*(p++));//对顺序表中的每个数据元素调用visit()函数 
	} 
	printf("\n");//输出换行 
	return OK;//操作成功 
}
//将顺序表中的所有数据元素自增1 
void auto_increment(ElemType &e){
	e++;
}
//输出顺序表中的所有数据元素 
void print(ElemType &e){
	printf("%d ", e);
}

int main(){
	//定义顺序表L
	SqList L; 
	
	//创建一个空的顺序表L 
	InitList_Sq(L); 
	
	//初始化顺序表L
	int n = 10;//需要向顺序表L中插入10个数据元素 
	for(int i = 1; i <= n; i++){//i表示顺序表L中数据元素的位序 
		ListInsert_Sq(L, i, i);//向顺序表L中插入数据元素 
	} 
	
	//输出顺序表L中的所有数据元素
	printf("顺序表L中的所有数据元素为:\n");
	ListTraverse_Sq(L, print);//依次输出顺序表L中的数据元素 
	
	//将顺序表L中的所有数据元素自增1并输出
	ListTraverse_Sq(L, auto_increment);//依次将顺序表L中的数据元素自增1 
	printf("自增1后,顺序表L中的所有数据元素为:\n");
	ListTraverse_Sq(L, print);
	
	//判断顺序表L是否为空表
	printf("\n若输出1,则顺序表L为空表;若输出0,则顺序表L不为空表:\n%d\n", ListEmpty_Sq(L)); 
	
	//输出顺序表L中的数据元素个数 
	printf("\n顺序表L中的数据元素个数为:\n%d\n", ListLength_Sq(L));
	
	//获取顺序表L中第i个数据元素
	int e0 = 0, i = 5;//i表示数据元素的位序 
	GetElem_Sq(L, i, e0);//将第i个数据元素存于e0中 
	printf("\n顺序表L中第%d个数据元素为:\n%d\n", i, e0); 
	
	//输出顺序表L中与指定数据元素满足一定关系的数据元素的位序(此实例中为相等关系)
	int e1 = 4;//e1为指定的数据元素
	printf("\n与%d具有相等关系的数据元素的位序为:\n%d\n", e1, LocateElem_Sq(L, e1, Equal));//返回顺序表L中与e具有相等关系的数据元素的位序
	 
	//输出指定数据元素的前驱
	int e2 = 5;//e2为指定的数据元素
	int pre_e2 = 0;//pre_e2用于存储e2的前驱
	PriorElem_Sq(L, e2, pre_e2);//获取e2的前驱并将其存于pre_e2中
	printf("\n%d的前驱为:\n%d\n", e2, pre_e2); 
	
	//输出指定数据元素的后继
	int e3 = 4;//e3为指定的数据元素
	int next_e3 = 0;//next_e3用于存储e3的后继
	NextElem_Sq(L, e3, next_e3);//获取e3的后继并将其存于next_e3中
	printf("\n%d的后继为:\n%d\n", e3, next_e3);
	
	//向顺序表中插入指定数据元素
	int i1 = 4;//i1为插入位置的位序
	int e4 = 25;//e4为要出入的指定数据元素
	printf("\n插入数据元素前,顺序表L的长度和存储空间大小分别为:\n%d和%d", L.length, L.listsize);
	ListInsert_Sq(L, i1, e4);//向顺序表L中插入e4
	printf("\n插入数据元素后,顺序表L的长度和存储空间大小分别为:\n%d和%d\n", L.length, L.listsize);
	printf("插入数据元素后,顺序表L的所有数据元素为:\n");
	ListTraverse_Sq(L, print);
	
	//向顺序表中删除指定数据元素
	int i2 = 3;//i2为删除位置的位序
	int e5 = 0;//e5用于存储被删除的数据元素 
	printf("\n删除数据元素前,顺序表L的长度和存储空间大小分别为:\n%d和%d", L.length, L.listsize);
	ListDelete_Sq(L, i2, e5);//删除顺序表L中位序为i2的数据元素并将其存于e5中 
	printf("\n删除数据元素后,顺序表L的长度和存储空间大小分别为:\n%d和%d\n", L.length, L.listsize);
	printf("删除的数据元素为:\n%d\n", e5);
	printf("删除数据元素后,顺序表L的所有数据元素为:\n");
	ListTraverse_Sq(L, print);
	
	//将顺序表重置为空表
	printf("\n(顺序表L重置为空表前)若输出1,则顺序表L为空表;若输出0,则顺序表L不为空表:\n%d", ListEmpty_Sq(L)); 
	ClearList_Sq(L);//将顺序表L值为空表
	printf("\n(顺序表L重置为空表后)若输出1,则顺序表L为空表;若输出0,则顺序表L不为空表:\n%d\n", ListEmpty_Sq(L));

	//销毁顺序表 
	printf("\n(销毁顺序表L前)顺序表L的基地址、长度和存储空间大小分别为:\n%d、%d、%d", L.elem, L.length, L.listsize);
	DestroyList_Sq(L);//销毁顺序表L
	printf("\n(销毁顺序表L后)顺序表L的基地址、长度和存储空间大小分别为:\n%d、%d、%d\n", L.elem, L.length, L.listsize);
	
	return 0;
} 
