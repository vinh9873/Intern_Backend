#pragma once

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
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

  ENDPOINT("PUT", "/files/upload", upload) {
    
    auto res = m_fileService->uploadFile();
    return createDtoResponse(Status::CODE_200, res);
  }
};

#include OATPP_CODEGEN_END(ApiController)
