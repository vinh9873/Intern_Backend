#pragma once

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/protocol/http/incoming/Request.hpp"
#include "service/FileService.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class FileController : public oatpp::web::server::api::ApiController {
private:
  std::shared_ptr<FileService> m_fileService;

public:
  
  FileController(const std::shared_ptr<ObjectMapper>& objectMapper,
                 const std::shared_ptr<FileService>& fileService)
    : oatpp::web::server::api::ApiController(objectMapper)
    , m_fileService(fileService)
  {}

  ENDPOINT("PUT", "/files/upload", upload,
           REQUEST(std::shared_ptr<oatpp::web::protocol::http::incoming::Request>, request)) {
    auto content = request->readBodyToString();
    return createResponse(Status::CODE_200, content);
  }
};

#include OATPP_CODEGEN_END(ApiController)
