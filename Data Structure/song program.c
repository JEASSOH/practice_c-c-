#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct Song
{
    char artist[20];
    char title[30];
}Song;

typedef struct Playlist {
    int no_of_songs;
    Song songs[10];
}Playlist;

int main()
{
    Playlist playlist;
    int i;

    scanf("%d", &playlist.no_of_songs);

    for (i = 0; i < playlist.no_of_songs; i++)
    {
        printf("%d 번째 노래 정보 입력\n", i + 1);
        printf("아티스트:");
        scanf("%s", playlist.songs[i].artist);
        printf("제목:");
        scanf("%s", playlist.songs[i].title);
    }

    printf("No   Artist                 Title\n");
    printf("==   ======                 =====\n");

    for (i = 0; i < playlist.no_of_songs; i++)
    {
        printf("%d", i + 1);
        printf("\t%s", playlist.songs[i].artist);
        printf("\t\t\t%s\n", playlist.songs[i].title);
    }

    return 0;
}