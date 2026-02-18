#pragma once

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "dto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class HelloController : public oatpp::web::server::api::ApiController {
public:

  HelloController(const std::shared_ptr<ObjectMapper>& objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper) {}

  ENDPOINT("GET", "/hello", hello) {
    auto res = oatpp::Fields<oatpp::String>::createShared();
    res["message"] = "Hello Intern";
    return createDtoResponse(Status::CODE_200, res);
  }

  ENDPOINT("POST", "/sum", sum,
           BODY_DTO(oatpp::Object<SumRequestDto>, body)) {
    auto response = SumResponseDto::createShared();
    response->result = body->a + body->b;
    return createDtoResponse(Status::CODE_200, response);
  }

};

#include OATPP_CODEGEN_END(ApiController)
