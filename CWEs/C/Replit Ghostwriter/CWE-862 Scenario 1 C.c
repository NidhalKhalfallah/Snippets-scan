#include <stdio.h>
#include <curl/curl.h>
//Send a request to a hospital website to view medical information of a patient
int main(int argc, char *argv[])
{
  CURL *curl;
  CURLcode res;
  char *url = "http://www.hospitalservices.com/hospital/medical/patient/viewmedicalinformation.php";
  char *postdata = "patientid=1&patientname=John&patientsex=M&patientage=18&patientbloodtype=O+&patientbloodtype=B+&patientbloodtype=AB&patientbloodtype=A&patientbloodtype=O&patientbloodtype=A&patientbloodtype=A&patientbloodtype=A&patientbloodtype=A&patientbloodtype=A&patientbloodtype=A&patientbloodtype=A";

  curl = curl_easy_init();
  if(curl)
    {
      curl_easy_setopt(curl, CURLOPT_URL, url);
      curl_easy_setopt(curl, CURLOPT_POST, 1L);
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);
    }
  return 0;
}
