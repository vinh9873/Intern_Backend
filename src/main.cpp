#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/component.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/* ========= DTO ========= */

//Request DTO
class SumRequestDto : public oatpp::DTO {

  DTO_INIT(SumRequestDto, DTO)

  DTO_FIELD(Int32, a);
  DTO_FIELD(Int32, b);

};

//Response DTO
class SumResponseDto : public oatpp::DTO {

  DTO_INIT(SumResponseDto, DTO);

  DTO_FIELD(Int32, result);

};

#include OATPP_CODEGEN_END(DTO)

#include OATPP_CODEGEN_BEGIN(ApiController)

class HelloController : public oatpp::web::server::api::ApiController {
public:
  HelloController(OATPP_COMPONENT(std::shared_ptr<oatpp::parser::json::mapping::ObjectMapper>, objectMapper))
    : ApiController(objectMapper) {}

  // GET /hello
  ENDPOINT("GET", "/hello", hello) {
    auto res = oatpp::Fields<oatpp::String>::createShared();
    res["message"] = "Hello Intern";
    return createDtoResponse(Status::CODE_200, res);
  }

  //POST /sum
  ENDPOINT("POST", "/sum", sum, BODY_DTO(oatpp::Object<SumRequestDto>, body)){
  
   auto response = SumResponseDto::createShared();
   response->result = body->a + body->b;

   return createDtoResponse(Status::CODE_200, response);
  }

};

#include OATPP_CODEGEN_END(ApiController)

int main() {
  oatpp::base::Environment::init();

  // Connection provider
  auto connectionProvider =
    oatpp::network::tcp::server::ConnectionProvider::createShared({"0.0.0.0", 8000});

  // Router
  auto router = oatpp::web::server::HttpRouter::createShared();

  // Object mapper
  auto objectMapper =
    oatpp::parser::json::mapping::ObjectMapper::createShared();

  // Controller
  auto controller = std::make_shared<HelloController>(objectMapper);
  router->addController(controller);

  // Connection handler
  auto connectionHandler =
    oatpp::web::server::HttpConnectionHandler::createShared(router);

  // Server
  oatpp::network::Server server(connectionProvider, connectionHandler);
  server.run();

  oatpp::base::Environment::destroy();
}
