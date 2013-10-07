#include "circular_queue.h"
#include <stdio.h>
#include <assert.h>

void case_1() {
    printf("==== case 1 ====\n");
    Queue *queue = NULL;
    int rc;
    int i;
    int element;

    queue = initialize(3);
    assert(NULL != queue);
    assert(0 == size(queue));
    rc = enqueue(queue, 1);
    assert(1 == size(queue));
    rc = enqueue(queue, 2);
    assert(2 == size(queue));
    rc = enqueue(queue, 3);
    assert(3 == size(queue));
    rc = enqueue(queue, 3);
    assert(0 != rc);
    for (i = 0; i < 3; ++i) {
        rc = dequeue(queue, &element);
        assert(0 == rc);
        printf("%d\n", element);
    }

    rc = dequeue(queue, &element);
    assert(0 != rc);

    rc = destroy(queue);
    assert(0 == rc);
    queue = NULL;
}

void case_2() {
    printf("==== case 2 ====\n");
    Queue *queue = NULL;
    int rc;
    int i;
    int element;

    queue = initialize(3);
    assert(NULL != queue);
    assert(0 == size(queue));

    for (i = 0; i < 10; ++i) {
        rc = enqueue(queue, i);
        assert(0 == rc);
        assert(1 == size(queue));

        rc = dequeue(queue, &element);
        assert(0 == rc);
        printf("%d\n", element);
    }
}

int main(int argc, char** argv) {
    case_1();
    case_2();
    return 0;
}
