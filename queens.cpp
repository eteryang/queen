#include <stdio.h>
#include <math.h>
//符号@代表皇后,*代表空
//皇后不能在同一行同一列和45度角连线上
//queenArr[0]=3,表示皇后在第一行的第4列的位置上
void showQueens(int queenArr[], int nLen,int nSolution) {
	printf(".........solution %d.............\n", nSolution);
	for (int i = 0; i < nLen; i++) {
		if (queenArr[i] == -1) {		//如果没有定义皇后，输出*
			for (int j = 0; j < nLen; j++) {
				printf("*");
			}
			printf("\n");
			continue;
		}
		//输出皇后前面空余部分
		for (int j = 0; j < queenArr[i]; j++) {
			printf("*");
		}
		printf("@");  //打印皇后
		//输出皇后后面空余部分
		for (int j = 0; j < nLen - queenArr[i] - 1; j++) {  //未打印的空余数为总长度-列数-1
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");
}


bool isClash(int queenArr[],int nRow) {   //判断方案是否有效,clash:冲突
	for (int nColumn = 0; nColumn < nRow; nColumn++) {
		if (queenArr[nColumn] == queenArr[nRow]) {  //说明在相同的列上有冲突
			return true;
		}
		if (abs(queenArr[nColumn] - queenArr[nRow]) == abs(nRow - nColumn)) {
			return true;
		}
	}
	return false;
}
//回溯法（递归），每个行先找到合格的点位，再继续找下一行
void putQueen(int queenArr[], int nRow, int nLen,int &nSolution) {
	for (int i = 0; i < nLen; i++) {
		queenArr[nRow] = i;  //把皇后放在当前的循环位置，即循环行的列位置上
		//循环检查冲突isClash方法，如果已经有冲突，直接忽略下面皇后位置摆放
		if (!isClash(queenArr, nRow)) {
			//没有冲突
			if (nRow == nLen - 1) {
				//全部8行已经解析完成
				nSolution++;
				showQueens(queenArr,nLen, nSolution);
			}
			else {
				//调用本身，下一行皇后位置
				putQueen(queenArr, nRow + 1,nLen, nSolution);
			}
		}
	}
}

#define QUEENCOUNT 9
int main(){
	int queenArr[QUEENCOUNT];
	int nSolution = 0;
	putQueen(queenArr, 0,QUEENCOUNT,nSolution);//从第0行开始放
	return 0;
}