#include<stdio.h>



//1������
//double sum(double n)
//{
//    if(n == 1)
//    return 1;
//
//    else
//    return 1 / n + sum(n - 1);
//
//}

//2������
//int sum(int n) {
//    for(int i = 0; i < n; i++)
//        return (n + sum(n - 1));
//}


struct Song
{
    char artist[20]; 
    char title[30];


};


struct Playlist
{
    int no_of_songs;
    Song songs[10];

};

int main()
{
    //1�� �����Լ�
    /*double n;
    scanf_s("%lf", &n);
    printf("�� = %lf\n", sum(n));*/

    /*2������
    int sol = sum(5);
    printf("�� = %d", sol);*/

    //3������

    struct Playlist p1;
    scanf_s("%s", p1.songs->artist);
    printf("%s", p1);


}
