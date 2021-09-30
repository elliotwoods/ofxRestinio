#pragma once

#include <restinio/all.hpp>
#include <nlohmann/json.hpp>

class ofxRestinio {
public:
	struct Request {
		nlohmann::json body;
	};

	struct Response {
		nlohmann::json body;
	};

	virtual ~ofxRestinio();
	void init(int port, const std::string& address= "localhost");
	void close();
protected:
	restinio::running_server_handle_t<restinio::default_traits_t> serverHandle;
};