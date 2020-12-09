# 10. Найти вершины с максимальной степенью вершины
## Алгоритм:
void Max_power(int e, int v, int matr[v][e]){
    int verse = -1, power = -1,temp_zero = 0,check = 0,memory = -1;
    int temp_matr[v];

    for(int i = 0; i < v; ++i ){
        temp_matr[i] = 0;
    }

    for(int i = 0; i < e; ++i){
        temp_zero=0;
        check=0;
        for(int j = 0; j < v; ++j){
            if(matr[j][i] != 0){
                ++temp_matr[j];
                ++check;
                if (check == 1 ){
                    memory = j;
                }else{
                    memory = -1;
                }
            }
            else{
                temp_zero += 1;
            }
            if (temp_zero == v-1 && check == 1 ){
                ++temp_matr[memory];
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
