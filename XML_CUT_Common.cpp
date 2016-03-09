/*
XML切分 
By: ZYY
*/ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <process.h> 
#include <dir.h> 
#include <io.h>

int count,cut_num,ord,cut_len,length,head_row;
int cut_way;
char file_name[5000],file_cut_name[5000],class_name[5000],head[5000],end[5000],stmp[5000],dir_name[5000];

int main(){
    //strcpy(file_name ,"ClinVarFullRelease_00-latest");  //文件名
    printf("Please Input Filename (without '.xml'): ");
    gets(file_name);
    
    //strcpy(class_name ,"</ClinVarSet>");    //切分结束点 
    printf("Please Input Cut Tag (like '</***>'): ");
    gets(class_name);
    
    //文件头行数
    printf("Please Input Head Field's Row Number: ");
    scanf("%d",&head_row);
    gets(end);
    
    //strcpy(end , "</ReleaseSet>");  //xml结束字段 
    printf("Please Input End Field (like '</***>'): ");
    gets(end);
    
    
    int len,i;
    length = ord = count = 0;    
    char file_name_xml[5000];
    sprintf(file_name_xml,"%s.xml",file_name);
    
    
    while(1){
        //切割方式
        printf("Please Choose Cut Way (1.by number  2.by length): ");
        scanf("%d",&cut_way);
        
        if(cut_way == 1) {
            //cut_num = 10;
            printf("Please Input Cut Number: ");
            scanf("%d",&cut_num);
            
            if(!freopen(file_name_xml,"r",stdin)){
                printf("Can't find file [%s]\n",file_name);   
            }else{
                freopen(file_name_xml,"r",stdin);
                
                //xml head
                gets(head);
                for(i = 0;i < head_row-1;i ++){
                    gets(stmp);
                    sprintf(head,"%s\n%s\n",head,stmp);
                }
                
                //创建结果文件夹 
                sprintf(dir_name,"%s_ByNum_res",file_name);
                if(access(dir_name,0)){
                    sprintf(dir_name,"md %s_ByNum_res",file_name);
                    system(dir_name);
                }
                          
                sprintf(file_cut_name,"%s_ByNum_res\\%s_%05d.xml",file_name,file_name,ord);
                freopen(file_cut_name,"w",stdout);
                printf("%s\n",head);
                
                while(gets(stmp) != NULL){
                    printf("%s\n",stmp);
                    if(strcmp(stmp,class_name) == 0){
                        count ++;  
                        if(count % cut_num == 0){
                            printf("\n%s\n",end);
                            fclose(stdout);
                            
                            ord ++;
                            sprintf(file_cut_name,"%s_ByNum_res\\%s_%05d.xml",file_name,file_name,ord);
                            freopen(file_cut_name,"w",stdout);
                            printf("%s\n",head);
                        }
                    }
                }
            }
            
            break;
        }
        else if(cut_way == 2){
            //cut_len = 10000000; //切分文件大小（10000000约为10M） 
            printf("Please Input Cut length (approximate 1000000 at 1M): ");
            scanf("%d",&cut_len);
              
            if(!freopen(file_name_xml,"r",stdin)){
                printf("Can't find file [%s]\n",file_name);   
            }else{
                freopen(file_name_xml,"r",stdin);
                
                //xml head
                gets(head);
                for(i = 0;i < head_row-1;i ++){
                    gets(stmp);
                    sprintf(head,"%s\n%s\n",head,stmp);
                }
                
               //创建结果文件夹 
                sprintf(dir_name,"%s_ByLen_res",file_name);
                if(access(dir_name,0)){
                    sprintf(dir_name,"md %s_ByLen_res",file_name);
                    system(dir_name);
                }
                
                sprintf(file_cut_name,"%s_ByLen_res\\%s_%05d.xml",file_name,file_name,ord);
                freopen(file_cut_name,"w",stdout);
                printf("%s\n",head);
                
                while(gets(stmp) != NULL){
                    printf("%s\n",stmp);
                    length += strlen(stmp);
                    if(strcmp(stmp,class_name) == 0){
                        //count ++;  
                        //if(count % cut_num == 0){
                        if(length >= cut_len){
                            length = 0;
                            printf("\n%s\n",end);
                            fclose(stdout);
                            ord ++;
                            sprintf(file_cut_name,"%s_ByLen_res\\%s_%05d.xml",file_name,file_name,ord);
                            freopen(file_cut_name,"w",stdout);
                            printf("%s\n",head);
                        }
                    }
                }
            }
            
            break;
        }
        else{
            printf("ERROR!");
        }
    }
       
     
    fclose(stdin);
    fclose(stdout);
    system("pause");
    return 0;
}
