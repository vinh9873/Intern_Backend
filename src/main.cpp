#include <iostream>
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "controller/HelloController.hpp"

int main() {

  oatpp::base::Environment::init();

  auto connectionProvider =
    oatpp::network::tcp::server::ConnectionProvider::createShared({"127.0.0.1", 8080});

  auto router = oatpp::web::server::HttpRouter::createShared();
  auto objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

  auto controller = std::make_shared<HelloController>(objectMapper);
  router->addController(controller);

  auto connectionHandler =
    oatpp::web::server::HttpConnectionHandler::createShared(router);

  oatpp::network::Server server(connectionProvider, connectionHandler);

  std::cout << "Server started at http://127.0.0.1:8080\n";
  server.run();

  oatpp::base::Environment::destroy();
}
