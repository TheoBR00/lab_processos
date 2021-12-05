#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <curl/curl.h>


int m;
int n = 0;

int main(int argc, char **argv){
    pid_t filho;

    int fp;

    

    FILE *file;

    if(argc < 3){
        //printf("Entrou argc < 3\n");
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
           //printf("Linha 87: %c\n", link[j]);
           j++;
       }
       //sleep(10);
       link[j++] = '.';
       link[j++] = 'h';
       link[j++] = 't';
       link[j++] = 'm';
       link[j++] = 'l';
       link[j++] = '\0';

        
        //printf("Link: %s\n", link);
        //sleep(10);

        //fp = fopen(argv[3], "wb");
        //file = open("lista_baixa.txt", O_WRONLY | O_CREAT, 0700);
        file = fopen(link, "wb");

        //printf("Abriu arquivo\n");

        CURL *curl = curl_easy_init();

        if(curl){

        //printf("Fez curl init\n");

        CURLcode r;
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        //printf("Fez 1 perform\n");
        //sleep(2);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        //printf("Fez segundo perform\n");
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        r = curl_easy_perform(curl);
        //printf("Fez terceiro perform\n");
        //sleep(2);

        printf("%d\n", r);

        if(CURLE_OK == r){
            char *info;
                r = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &info);

                //printf("Pegou info\n");

                if((CURLE_OK == r) && info){
                    printf("Resolvendo: %s\n", info);
                    printf("%s baixada com sucesso\n", argv[1]);
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

        //printf("Entrou else\n");

        FILE *escreve;

        char buf[5000];
        
        //char buf2[56];
        //char buf2[1000];

        char link[56];

    //filho = fork();

    //if(filho == 0){

       // FILE *fp_2;

       //printf("Filho = 0\n");

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

        int i = 0;

        //int j = 0;

        int comeca = 7;

        char buf2[5000];

        //pid_t processo_filho;

        int n = 0;

        int m;

        //while(bytes_read > 0 || ativa == 1){
        //    bytes_read = read(fp, &buf, 1);
        //    printf("Buf %d: %s\n", k, buf);

            //m = n;

            //n++;

        //    filho = fork();

        //    if(filho == 0){

         //   processo_filho = getpid();

        //    rep++;

            //printf("REP: %d\n", rep);

            //printf("BYTES READ: %d\n", bytes_read);
            //char buf2[5000];

            //int i = 0;

            //int l = 0;

            //int comeca = 7;

            //int p;

            while(ativa){
                bytes_read = read(fp, &buf, 1);

                int j = 0;

                //printf("Bytes read: %d\n", bytes_read);

                //printf("Buf original: %s\n", buf);


            //for(m = n; buf[m] != '\n'; m++){
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
                if(buf[m] == '\n'){
                    printf("Bytes read: %d\n", bytes_read);
                    buf2[i] = '\0';
                    printf("URL: %s\n", buf2);

                    printf("buf2[0] = %c\n", buf2[0]);
                    printf("buf2[1] = %c\n", buf2[1]);
                    printf("buf2[2] = %c\n", buf2[2]);
                    printf("buf2[3] = %c\n", buf2[3]);
                    printf("buf2[4] = %c\n", buf2[4]);
                    printf("buf2[5] = %c\n", buf2[5]);

                    if (buf2[0]=='h' && buf2[1]=='t' && buf2[2]=='t' && buf[3]=='p' && buf[4]==':' ) {
                            int comeca = 7;
                            printf("l = 7\n");
                    } else if (buf[0]=='h' && buf[1]=='t' && buf[2]=='t' && buf[3]=='p' && buf[4]=='s' && buf[5] == ':' ) {
                            int comeca = 8;
                            printf("l = 8\n");
                        }


                    //printf("Link: %s\n", link);

                    for(j = 0; buf2[j] != '\0'; comeca++){
                        link[j] = buf2[comeca];
                        if(link[j] == '.'){
                            link[j] = '_';
                        }
                        if(link[j] == '.' || link[j] == '/'){
                            link[j] = '_';
                        }
                        j++;
                    }
                    printf("l: %d URL: %s\n", j, buf2);
                    //link[j-9] = '.';
                    //link[j-8] = 'h';
                    //link[j-7] = 't';
                    //link[j-6] = 'm';
                    //link[j-5] = 'l';
                    //link[j-4] = '\0';
                    sleep(2);
                    printf("Link: %s\n", link);
                    //sleep(10);
                    escreve = fopen(link, "wb");

                    //i++;
                    i = m;
                    //j = 0;

                    filho = fork();

                    if(filho == 0){

                        sleep(2);

                        CURL *curl = curl_easy_init();

                        

                        //printf("Buf atual: %s\n", buf2);

                        CURLcode r;

                        //if(buf2[0] == 'h' && buf2[1] == 'h'){
                        //    buf2[0] = "";
                        //    buf2[1] = "";
                        //}
                        //printf("URL: %s\n", buf2);
                        curl_easy_setopt(curl, CURLOPT_URL, buf2);
                        curl_easy_setopt(curl, CURLOPT_WRITEDATA, escreve);
                        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
                        r = curl_easy_perform(curl);
                        sleep(4);

                        printf("Buf2: %s\n", buf2);

                        printf("r: %d\n", r);

                        if(CURLE_OK == r){
                            char *info;
                            r = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &info);

                            printf("Pegou info\n");

                            if((CURLE_OK == r) && info){
                                printf("Resolvendo: %s\n", info);
                                printf("%s resolvida com sucesso!\n", buf2);
                                printf("Passou 1\n");
                                //sleep(2);
                                //sleep(10);
                                return 0;

                                //char buf2[1000];
                                //write(fd1, info, 1);
                                //close(fd1);
                            }
                        }

                        else{
                            printf("Error: %s\n", curl_easy_strerror(r));
                            printf("Arquivo acabou!\n");
                            ativa = 0;
                            return 0;
                        }
                    




                        return 0;
                    }

                    //int wstatus;
                    //pid_t pid_terminou;

                    //pid_terminou = waitpid(filho, &wstatus, WNOHANG);
                    //return 0;
                    
                }

                else{
                    buf2[i] = buf[m];
                    i++;
                    if(bytes_read == 0){
                        break;
                    }
                }
                

                
                //if(buf[i] == EOF){
                //    return 0;
                //}

                //link[i] = buf2[i];
                //if(rep % 2 == 0){
                //    break;
                //}
                //printf("%c\n", buf2[i]);
                //i++;
            }
            //printf("M: %d\n", m);
            //buf2[i] = '\0';
            //i = 0;
            //sleep(1);
            //printf("URL: %s\n", buf2);

            //filho = fork();

        

            //buf2[i] = '\0';

            

            //if (buf2[0]=='h' && buf2[1]=='t' && buf2[2]=='t' && buf[3]=='p' && buf[4]==':' ) {
            //    comeca = 7;
                //printf("l = 7\n");
            //} else if (buf[0]=='h' && buf[1]=='t' && buf[2]=='t' && buf[3]=='p' && buf[4]=='s' && buf[5] == ':' ) {
            //    comeca = 8;
                //printf("l = 8\n");
            //}

            //printf("Link: %s\n", link);

            //for(l = 0; buf2[l] != '\0'; comeca++){
            //    link[l] = buf2[comeca];
             //   if(link[l] == '.'){
             //       link[l] = '_';
             //   }
             //   if(link[l] == '/' && buf2[comeca] != '\0'){
             //       link[l] = '_';
             //   }
            //    l++;
           // }

            //link[l-9] = '.';
            //link[l-8] = 'h';
            //link[l-7] = 't';
            //link[l-6] = 'm';
            //link[l-5] = 'l';
            //link[l-4] = '\0';

            //printf("link[0] = %c\n", link[0]);
            //printf("l: %d\n", l);
            //printf("link[1] = %c\n", link[1]);
            //printf("link[2] = %c\n", link[2]);
            //printf("link[3] = %c\n", link[3]);
            //printf("link[4] = %c\n", link[4]);

            //printf("Link: %s\n", link);
            
            //n = m;
            
            //n++;

            //escreve = fopen("lista_html.txt", "wb");
            //escreve = fopen(link, "wb");

            //CURL *curl = curl_easy_init();

            //printf("Buf atual: %s\n", buf2);

            //CURLcode r;
            //printf("URL: %s\n", buf2);
            //curl_easy_setopt(curl, CURLOPT_URL, buf2);
            //curl_easy_setopt(curl, CURLOPT_WRITEDATA, escreve);
            //curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
           // r = curl_easy_perform(curl);
            //sleep(2);

            //printf("r: %d\n", r);

            //if(CURLE_OK == r){
            //    char *info;
             //       r = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &info);

                    //printf("Pegou info\n");

            //        if((CURLE_OK == r) && info){
            //            printf("Resolvendo: %s\n", info);
            //            printf("%s resolvida com sucesso!\n", buf2);
                        //char buf2[1000];
                        //write(fd1, info, 1);
                        //close(fd1);
            //        }
            //}

            //else{
                //printf("Error: %s\n", curl_easy_strerror(r));
            //    printf("Arquivo acabou!\n");
            //    ativa = 0;
             //   return 0;
           // }

            //write(escreve, &buf, 1);
            //printf("%s\n", buf);
            //fprintf(fp, "%c", buf);
            //num++;
            //printf("%d\n", bytes_read);
            //k++;
            //sleep(2);
            //return 0;
       // }

       

       // m = n;


        //printf("%s\n", buf);

       // printf("Num: %d\n", num);

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

        


        //return 0;
    }

    //else{

        

    //    int wstatus;
    //    wait(&wstatus);

        //fclose(fp);

    //    printf("Filho acabou\n");
    //    printf("Terminou normal?: %d\n", WIFEXITED(wstatus));
    //}
    return 0;

       
}

