#include "components/SpatialForm.h"

namespace StarWarrior {

SpatialForm::SpatialForm(std::string spatialFormFile) {
	this->spatialFormFile = spatialFormFile;
}

std::string SpatialForm::getSpatialFormFile() {
	return spatialFormFile;
}

}