#include "structures/resource.h"

#ifndef RESOURCE_HANDLING_H_
    #define RESOURCE_HANDLING_H_
    resource_t *create_resource(int fd);
    void free_resource(resource_t *resource);
    void display_render_tex(resource_t *resource);
#endif /* !RESOURCE_HANDLING_H_ */