#include "app.h"

int main(int argc, char* argv[]) {

    App* app = App::getInstance(argc, argv);
    app->run();

    return 0;
}
