#ifndef STARWARRIOR_SPATIALFORM_H
#define STARWARRIOR_SPATIALFORM_H

#include "hecate/Component.h"

#include <string>

namespace StarWarrior {

class SpatialForm : public hecate::Component {
	SpatialForm(std::string spatialFormFile);
	std::string getSpatialFormFile() const;

private:
	std::string spatialFormFile;
};

}

#endif
