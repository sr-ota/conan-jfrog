/* SPDX-License-Identifier: MIT */

#include <stdio.h>
#include <curl/curl.h>

int
main(void)
{
  curl_global_init(0);
  printf("curl version:\n  '%s'\n", curl_version());

  curl_global_cleanup();
  return 0;
}
