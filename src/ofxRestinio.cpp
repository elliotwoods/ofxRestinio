#include "ofxRestinio.h"

using namespace std;

//---------
ofxRestinio::~ofxRestinio()
{
    this->close();
}

//---------
void
ofxRestinio::init(int port, const string & address)
{
    this->close();

    this->serverHandle = restinio::run_async(
        restinio::own_io_context(),
        restinio::server_settings_t<restinio::default_traits_t>{}
            .address(address)
            .port(port)
            .request_handler([](auto req) {
            return req->create_response()
                .append_header(restinio::http_field::content_type, "application/json; charset=utf-8")
                .set_body("Hello, World!").done();
                }),
        1);
}

//---------
void
ofxRestinio::close()
{
    if (this->serverHandle) {
        this->serverHandle->stop();
        this->serverHandle->wait();
        this->serverHandle.reset();
    }
}