include(vcpkg_common_functions)

include(${CURRENT_INSTALLED_DIR}/share/qt5modularscripts/qt_modular_library.cmake)

qt_modular_library(qtdeclarative 30d3ddfabceaf48666cb5ebc5c3a25318152daeed599b1a0a1b3c2feff353708de4760472babbe55a685582c0640a2789fa2fa239d151d17fe2b36950836f7ee)

#file(REMOVE_RECURSE ${CURRENT_PACKAGES_DIR}/tools/qt5-declarative/platforminputcontexts)