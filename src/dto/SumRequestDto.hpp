#pragma once

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class SumRequestDto : public oatpp::DTO {
  DTO_INIT(SumRequestDto, DTO)
  DTO_FIELD(Int32, a);
  DTO_FIELD(Int32, b);
};

class FileUploadResponseDto : public oatpp::DTO {
  DTO_INIT(FileUploadResponseDto, DTO)
  DTO_FIELD(String, filename);
  DTO_FIELD(String, contentType);
  DTO_FIELD(Int64, size);
  DTO_FIELD(String, content);
};

class SumResponseDto : public oatpp::DTO {
  DTO_INIT(SumResponseDto, DTO)
  DTO_FIELD(Int32, result);
};

#include OATPP_CODEGEN_END(DTO)
