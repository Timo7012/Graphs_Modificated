#include <stdio.h>
#include <stdlib.h>

void Max_power(int e, int v, int matr[v][e]){
    int verse=-1, power=-1;
    int temp_matr[v];

    for(int i = 0; i < v; ++i ){
        temp_matr[i] = 0;
    }

    for(int i = 0; i < e; ++i){
        for(int j = 0; j < v; ++j){
            int temp_zero=0;
            if(matr[j][i] != 0){
                ++temp_matr[j];
            }
            else{
                temp_zero += 1;
            }
            if (temp_zero == v-1 && ++temp_matr[j] == 1){
                ++temp_matr[j];
            }
        }
    }
    for(int i = 0; i<v; ++i ){
        if (temp_matr[i]>power){
            power = temp_matr[i];
            verse = i;
        }
    }
    printf("Max power of verse %d is %d ",verse,power);
}





int main(void) {
    int e = 0, v = 0,ans1 = 0,ans2= 0;
    printf("Enter edges and verses of graph:\nV=");
    scanf("%d", &v);
    printf("\nE=");
    scanf("%d", &e);
    printf("Graph is directed:\n 1 - yes\n 0 - no\n answer: ");
    scanf("%d",&ans1);
    printf("Graph is weighted:\n 1 - yes\n 0 - no\n answer: ");
    scanf("%d",&ans2);
    int* edge = NULL;
    if(ans2){
        edge = (int*)malloc(e*sizeof(int));
        for (int i=0;i<e;++i){
            printf("\ne%d=",i+1);
            scanf("%d", &edge[i]);
        }
    }
    int matr[v][e];
    for(int i = 0; i < v; ++i){
        for(int j = 0; j < e; ++j){
            scanf("%d",&matr[i][j]);
        }
    }

    Max_power(e,v,matr);

    FILE *gfile = fopen("C:\\Users\\Timur\\Desktop\\gfile.dot","w+");
    if(gfile == NULL){
        printf("File is not exist or not created");
        return 0;
    };
    if(ans1){fprintf(gfile, "digraph graphname {\n");}
    else{fprintf(gfile, "graph graphname {\n");}
    for(int i=0;i<v;++i){
        fprintf(gfile,"\t%d;\n",i);
    }
    for (int i = 0; i < e; ++i){
        int first = -1, second = -1;
        for (int j = 0; j < v; ++j){
            if (matr[j][i]){
                if (ans1){
                    if(matr[j][i] == -1){
                        second = j;
                    } else {
                        first = j;
                    }
                } else {
                    if (first + 1){
                        second = j;
                    } else {
                        first = j;
                    }
                }
            }
        }
        fprintf(gfile, "\t%d -", first);
        if(ans1){
            fputc('>', gfile);
        } else {
            fputc('-', gfile);
        }
        if (second != -1)
            fprintf(gfile," %d", second);
        else
            fprintf(gfile," %d", first);
        if(ans2){
            fprintf(gfile, "[label=%d]", edge[i]);
        }
        fprintf(gfile,";\n");
    }
    fprintf(gfile, "}");
    fclose(gfile);



    if(e>(((v-1)*(v-2))/2)){
        printf("\nGraph is connected");
    }else{
        printf("\nGraph is not connected");
    }
    system("dot -Tpng gfile.dot -o graph.png");
    return 0;
}
