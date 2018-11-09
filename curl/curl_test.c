#include <strings.h>
#include <stdio.h>
#include <curl/curl.h>
#include <curl/easy.h>
/*
curl 版本显示
gcc curl_test.c -o curl_test -lcurl

*/
int main(int argc, char *argv[])
{
  curl_version_info_data *data = curl_version_info(CURLVERSION_NOW);

  if (data && data->ssl_version && *data->ssl_version) {
    const char *ptr = data->ssl_version;
    printf("ssl_version %s\n", ptr );
   
  }
  return 1;
}