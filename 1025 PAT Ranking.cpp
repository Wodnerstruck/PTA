#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct Student {
    char id[15];
    int score;
    int location_number;
    int local_rank;
}stu[30010];

//比较函数：先按分数递减，再按准考证号递增
bool cmp(Student a,Student b){
    if(a.score != b.score) return a.score>b.score;
    else return strcmp(a.id,b.id)<0;
}

int main(){
    int n,k;//number of locations & number of testees per location
    int num=0;//number of testees
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            scanf("%s %d",stu[num].id,&stu[num].score);
            stu[num].location_number=i;//i is location_number
            num++;
        }
   sort(stu+num-k,stu+num,cmp);// sort testees in every location
   stu[num-k].local_rank=1;//该考场第一位学生考场排名为1
   for(int j=num-k+1;j<num;j++){
    if(stu[j].score==stu[j-1].score){
        stu[j].local_rank=stu[j-1].local_rank;//分数相同排名相同
    }
    else{
        stu[j].local_rank=j+1-(num-k);//考场排名等于排序后在考场的实际名次
    }
   }
}
printf("%d\n",num);//考试总人数+回车
sort(stu,stu+num,cmp);//对所有考试学生做排序
int r=1;//当前考生排名
for(int i=0;i<num;i++){
if(i>0&&stu[i].score!=stu[i-1].score){//i>0的条件防止数组越界
    r=i+1;
}
printf("%s %d %d %d\n",stu[i].id,r,stu[i].location_number,stu[i].local_rank);
}
return 0;
}