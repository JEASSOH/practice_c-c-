#include<stdio.h>



//1번문제
//double sum(double n)
//{
//    if(n == 1)
//    return 1;
//
//    else
//    return 1 / n + sum(n - 1);
//
//}

//2번문제
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
    //1번 메인함수
    /*double n;
    scanf_s("%lf", &n);
    printf("합 = %lf\n", sum(n));*/

    /*2번문제
    int sol = sum(5);
    printf("합 = %d", sol);*/

    //3번문제

    struct Playlist p1;
    scanf_s("%s", p1.songs->artist);
    printf("%s", p1);


}
