#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <curl/curl.h>

//void webDownloader(int argc, char *argv[], char *URL){

//    pid_t filho;

//    filho = fork();

//    if(filho == 0){

//        char arq1[100];

//        scanf("%s", arq1);

//        int fd1 = open(arq1, O_WRONLY | O_CREAT, 0700);

//        CURL *curl = curl_easy_init();

//        if(curl){

//            sleep(2);

//            CURLcode r;
//            curl_easy_setopt(curl, CURLOPT_URL, URL);
//            r = curl_easy_perform(curl);

//            if(CURLE_OK == r){
//                char *info;
//                r = curl_easy_get_info(curl, CURLINFO_CONTENT_TYPE, &info);

//                if((CURLE_OK == r) && info){
//                    printf("Resolvendo: %s\n", info);
//                    write(fd1, info, 1);
//                    close(fd1);
//                }
//            }
//
//            curl_easy_cleanup(curl);
//        }

//    }

//    else{
//        int wstatus;
//        wait(&wstatus);
//        printf("Filho acabou\n");
//    }

    
//}

void main(int argc, char **argv){
    pid_t filho;

    int fp;

    FILE *file;

    if(argc < 3){
        printf("Entrou argc < 3\n");
        char link[1000];

       int i = 0;
       int j = 0;
       
       if (argv[1][0]=='h' && argv[1][1]=='t' && argv[1][2]=='t' && argv[1][3]=='p' && argv[1][4]==':' ) {
           i =7;
       } else if (argv[1][0]=='h' && argv[1][1]=='t' && argv[1][2]=='t' && argv[1][3]=='p' && argv[1][4]=='s' && argv[1][5] == ':' ) {
           i = 8;
       }

        printf("%s\n", argv[1]);

       for(j = 0; argv[1][i] != '\0'; i++){
           link[j] = argv[1][i];
           if(link[j] == '.'){
               link[j] = '_';
           }
           printf("Linha 87: %c\n", link[j]);
           j++;
       }
       //sleep(10);
       link[j++] = '\0';

        
        printf("Link: %s\n", link);
        //sleep(10);

        //fp = fopen(argv[3], "wb");
        //file = open("lista_baixa.txt", O_WRONLY | O_CREAT, 0700);
        file = fopen("lista_baixa.txt", "wb");

        printf("Abriu arquivo\n");

        CURL *curl = curl_easy_init();

        if(curl){

        printf("Fez curl init\n");

        CURLcode r;
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        printf("Fez 1 perform\n");
        //sleep(2);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        printf("Fez segundo perform\n");
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        r = curl_easy_perform(curl);
        printf("Fez terceiro perform\n");
        //sleep(2);

        printf("%d\n", r);

        if(CURLE_OK == r){
            char *info;
                r = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &info);

                printf("Pegou info\n");

                if((CURLE_OK == r) && info){
                    printf("Resolvendo: %s\n", info);
                    //write(fd1, info, 1);
                    //close(fd1);
                }
        }

        else{
            printf("Error: %s\n", curl_easy_strerror(r));
        }
    }

        


        return 0;
    }

    else{

        printf("Entrou else\n");

        FILE *escreve;

        char buf[56];
        //char buf2[56];

    filho = 0;

    if(filho == 0){

       // FILE *fp_2;

       printf("Filho = 0\n");

       char link[1000];

       int i = 0;
       int j = 0;

       //printf("%c\n", argv[])
       
       if (argv[2][0]=='h' && argv[2][1]=='t' && argv[2][2]=='t' && argv[2][3]=='p' && argv[2][4]==':' ) {
           i =7;
           printf("i = 7\n");
       } else if (argv[2][0]=='h' && argv[2][1]=='t' && argv[2][2]=='t' && argv[2][3]=='p' && argv[2][4]=='s' && argv[2][5] == ':' ) {
           i = 8;
           printf("i = 8\n");
       }

        printf("%s\n", argv[2]);

       for(j = 0; argv[2][i] != '\0'; i++){
           link[j] = argv[2][i];
           if(link[j] == '.'){
               link[j] = '_';
           }
           printf("Linha 87: %c\n", link[j]);
           j++;
       }
       //sleep(10);
       link[j++] = '\0';

        
        printf("Link: %s\n", link);
        //sleep(10);

        //fp = fopen(argv[2], "rb");
        fp = open(argv[2], O_RDONLY, 0700);

        //sleep(2);
        //printf("%c\n", fp[0]);

        escreve = fopen("lista_html.txt", "wb");

        printf("Abriu arq\n");

        int bytes_read = 1;

        int num = 0;
        int k = 0;
        int rep = 0;

        int n = 0;

        int m;

        while(bytes_read > 0){
            bytes_read = read(fp, &buf, 55);
            printf("Buf %d: %s\n", k, buf);

            char buf2[56];

            int i = 0;

            for(m = n; buf[m] != '\0'; m++){
                //printf("%c\n", buf[m]);
                //if(buf[m] == '"'){
                //    rep++;
                //}
                if(buf[i] == '\n'){
                    i = 0;
                    break;
                }
                buf2[i] = buf[m];
                //if(rep % 2 == 0){
                //    break;
                //}
                printf("%c\n", buf2[m]);
                i++;
            }
            
            n = m;
            
            n++;

            CURL *curl = curl_easy_init();

            CURLcode r;
            printf("URL: %s\n", buf2);
            curl_easy_setopt(curl, CURLOPT_URL, buf2);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, escreve);
            curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
            r = curl_easy_perform(curl);
            sleep(2);

            printf("r: %d\n", r);

            if(CURLE_OK == r){
                char *info;
                    r = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &info);

                    printf("Pegou info\n");

                    if((CURLE_OK == r) && info){
                        printf("Resolvendo: %s\n", info);
                        printf("%s resolvida com sucesso!\n", buf2);
                        //write(fd1, info, 1);
                        //close(fd1);
                    }
            }

        else{
            printf("Error: %s\n", curl_easy_strerror(r));
        }

            //write(escreve, &buf, 1);
            //printf("%s\n", buf);
            //fprintf(fp, "%c", buf);
            num++;
            //printf("%d\n", bytes_read);
            k++;
            //sleep(2);
        }

        //printf("%s\n", buf);

        printf("Num: %d\n", num);

        //CURL *curl = curl_easy_init();

        //CURLcode r;
        //curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        //curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        //curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        //r = curl_easy_perform(curl);

        //printf("%d\n", r);

        //if(CURLE_OK == r){
        //    char *info;
        //        r = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &info);

        //        printf("Pegou info\n");

        //        if((CURLE_OK == r) && info){
        //            printf("Resolvendo: %s\n", info);
                    //write(fd1, info, 1);
                    //close(fd1);
        //        }
        //}

        //else{
        //    printf("Error: %s\n", curl_easy_strerror(r));
        //}

        


        return 0;
    }

    else{

        

        int wstatus;
        wait(&wstatus);

        //fclose(fp);

        printf("Filho acabou\n");
        printf("Terminou normal?: %d\n", WIFEXITED(wstatus));
    }


       //for(int j = 0; link[j] != '\0'; j++){

      // }

       fp = fopen(argv[2], "wb");


        //if(argv[1][0] == '-' && argv[1][1] == 'f'){
        //    fp_2 = fopen(argv[2], "wb");
        //}

        

        CURL *curl = curl_easy_init();

        if(curl){

            sleep(2);

            CURLcode r;
            curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
            r = curl_easy_perform(curl);

            printf("Fez perform\n");

            if(CURLE_OK == r){
                char *info;
                r = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &info);

                printf("Pegou info\n");

                if((CURLE_OK == r) && info){
                    printf("Resolvendo: %s\n", info);
                    //write(fd1, info, 1);
                    //close(fd1);
                }
            }
            else{
                printf("Error: %s\n", curl_easy_strerror(r));
            }

            printf("Terminou\n");

            fclose(fp);

            curl_easy_cleanup(curl);
        }

        //return 2;

    }

    //else{

        

    //    int wstatus;
    //    wait(&wstatus);

        //fclose(fp);

     //   printf("Filho acabou\n");
     //   printf("Terminou normal?: %d\n", WIFEXITED(wstatus));
    //}
}

