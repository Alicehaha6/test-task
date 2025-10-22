#include <stdio.h>
#include <string.h>

//定义一个结构体来存储当前栈顶的需要打印的次数和打印的内容
typedef struct{
    int nums;
    char content[128];
}ITEM;


//3[ab]2[a2[a3[b]]]ef
//3[a]2[bc]
//3[a2[c]]
//2[abc]3[cd]ef
//3[a2[b4[c]]]
int main(void){
    //栈总item列表
    ITEM arr[64]={0};
    //固定索引方向,模拟删除
    int outline_index=-1;
    //判断是否队列为空
    int counter=0;
    //固定当前索引，模拟删除后的索引位置
    int pointer=-1;

    char number_list[128]="";
    fgets(number_list,sizeof(number_list),stdin);
    number_list[strlen(number_list)-1]='\0';
    for (int i=0;i<strlen(number_list);i++){
        if (number_list[i]>='0' && number_list[i]<='9'){
            outline_index++;
            counter++;
            ITEM temp;
            temp.nums=number_list[i]-'0';
            arr[outline_index]=temp;
            pointer++;
        }
        if ((number_list[i]>='A' && number_list[i]<='Z') || (number_list[i]>='a' && number_list[i]<='z')){
            if (counter==0){
                printf("%c",number_list[i]);
                fflush(stdout);
            }
            strncat(arr[outline_index].content,number_list+i,1);
        }
        if (number_list[i]==']'){
            counter--;//出栈
            if (counter==0){//判断栈大小
                for (int k=0;k<arr[pointer].nums;k++){
                    printf("%s",arr[pointer].content);
                    fflush(stdout);//输出
                }
                pointer=outline_index;//栈为空，重置栈顶指针
            }else{
                for (int j=0;j<arr[pointer].nums;j++){
                    strcat(arr[pointer-1].content,arr[pointer].content);//给栈顶cat
                }
                pointer--;//出栈
            }
        }
    }

    return 0;
}