#pragma once

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "dto/SumRequestDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)
class FileController : public oatpp::web::server::api::ApiController {
public:
  
  FileController(const std::shared_ptr<ObjectMapper>& objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper) {}
  
  ENDPOINT("PUT", "/files/upload", upload) {
    auto res = oatpp::Fields<oatpp::String>::createShared();
    res["message"] = "File Uploaded!";
    return createDtoResponse(Status::CODE_200, res);
  }
};

#include OATPP_CODEGEN_END(ApiController)