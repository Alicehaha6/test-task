#include <stdio.h>
#include <string.h>

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
    ITEM arr[32]={0};
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
            counter--;
            if (counter==0){
                for (int k=0;k<arr[pointer].nums;k++){
                    printf("%s",arr[pointer].content);
                    fflush(stdout);
                }
                pointer=outline_index;
            }else{
                for (int j=0;j<arr[pointer].nums;j++){
                    strcat(arr[pointer-1].content,arr[pointer].content);
                }
                pointer--;
            }
        }
    }

    return 0;
}