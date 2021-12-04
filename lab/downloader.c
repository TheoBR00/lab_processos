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

int main(int argc, char **argv){
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
           if(link[j] == '.' || link[j] == '/'){
               link[j] = '_';
           }
           printf("Linha 87: %c\n", link[j]);
           j++;
       }
       //sleep(10);
       link[j++] = '.';
       link[j++] = 'h';
       link[j++] = 't';
       link[j++] = 'm';
       link[j++] = 'l';
       link[j++] = '\0';

        
        printf("Link: %s\n", link);
        //sleep(10);

        //fp = fopen(argv[3], "wb");
        //file = open("lista_baixa.txt", O_WRONLY | O_CREAT, 0700);
        file = fopen(link, "wb");

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

        char buf[5000];
        
        //char buf2[56];
        //char buf2[1000];

        char link[56];

    filho = fork();

    if(filho == 0){

       // FILE *fp_2;

       printf("Filho = 0\n");

       //printf("%c\n", argv[])
       
       
        //sleep(10);

        //fp = fopen(argv[2], "rb");
        fp = open(argv[2], O_RDONLY, 0700);

        //sleep(2);
        //printf("%c\n", fp[0]);

        printf("Abriu arq\n");

        int bytes_read = 1;

        int ativa = 1;

        int num = 0;
        int k = 0;
        int rep = 0;

        //int l = 0;

        int n = 0;

        int m;

        while(bytes_read > 0 || ativa == 1){
            bytes_read = read(fp, &buf, 5000);
            //printf("Buf %d: %s\n", k, buf);

            rep++;

            //printf("REP: %d\n", rep);

            //printf("BYTES READ: %d\n", bytes_read);
            char buf2[5000];

            int i = 0;

            int l = 0;

            int comeca = 7;

            //int value = 10;

            //char test = '\n';

            //int p;

            for(m = n; buf[m] != '\n'; m++){
                //printf("%c\n", buf[m]);
                //if(buf[m] == '"'){
                //    rep++;
                //}
                //value = strcmp(&buf[i], &test);
                //printf("Value: %d\n", value);

                //if(buf[i] == '\n'){
                //    i = 0;
                //    break;
                //}
                buf2[i] = buf[m];

                //if(buf[i] == EOF){
                //    return 0;
                //}

                //link[i] = buf2[i];
                //if(rep % 2 == 0){
                //    break;
                //}
                //printf("%c\n", buf2[i]);
                i++;
            }
            buf2[i] = '\0';
            //i = 0;
            sleep(1);
            printf("URL: %s\n", buf2);

            //buf2[i] = '\0';

            

            if (buf2[0]=='h' && buf2[1]=='t' && buf2[2]=='t' && buf[3]=='p' && buf[4]==':' ) {
                comeca = 7;
                //printf("l = 7\n");
            } else if (buf[0]=='h' && buf[1]=='t' && buf[2]=='t' && buf[3]=='p' && buf[4]=='s' && buf[5] == ':' ) {
                comeca = 8;
                //printf("l = 8\n");
            }

            //printf("Link: %s\n", link);

            for(l = 0; buf2[l] != '\0'; comeca++){
                link[l] = buf2[comeca];
                if(link[l] == '.'){
                    link[l] = '_';
                }
                if(link[l] == '/' && buf2[comeca] != '\0'){
                    link[l] = '_';
                }
                l++;
            }

            link[l-9] = '.';
            link[l-8] = 'h';
            link[l-7] = 't';
            link[l-6] = 'm';
            link[l-5] = 'l';
            link[l-4] = '\0';

            printf("link[0] = %c\n", link[0]);
            printf("l: %d\n", l);
            //printf("link[1] = %c\n", link[1]);
            //printf("link[2] = %c\n", link[2]);
            //printf("link[3] = %c\n", link[3]);
            //printf("link[4] = %c\n", link[4]);

            printf("Link: %s\n", link);
            
            n = m;
            
            n++;

            //escreve = fopen("lista_html.txt", "wb");
            escreve = fopen(link, "wb");

            CURL *curl = curl_easy_init();

            //printf("Buf atual: %s\n", buf2);

            CURLcode r;
            //printf("URL: %s\n", buf2);
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
                        //char buf2[1000];
                        //write(fd1, info, 1);
                        //close(fd1);
                    }
            }

            else{
                //printf("Error: %s\n", curl_easy_strerror(r));
                printf("Arquivo acabou!\n");
                ativa = 0;
                return 0;
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


       
}
return 0;
}

