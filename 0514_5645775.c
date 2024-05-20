#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef int element;

typedef struct {
    element array[MAX_SIZE];
    int size;
} ArrayListType;

bool is_full(ArrayListType* L) {
    return L->size == MAX_SIZE;
}

bool is_empty(ArrayListType* L) {
    return L->size == 0;
}

void print_list(ArrayListType* L) {
    int i;
    for (i = 0; i < L->size; i++) {
        printf("%d -> ", L->array[i]);
    }
    printf("NULL\n");
}

void insert(ArrayListType* L, int position, element value) {
    if (position < 0 || position > L->size || is_full(L)) {
        printf("위치 오류\n");
        return;
    }
    for (int i = L->size; i > position; i--) {
        L->array[i] = L->array[i - 1];
    }
    L->array[position] = value;
    L->size++;
    printf("삽입 완료. 데이터 이동 횟수: %d\n", L->size - position - 1);
}

void delete(ArrayListType* L, int position) {
    if (position < 0 || position >= L->size || is_empty(L)) {
        printf("위치 오류\n");
        return;
    }
    for (int i = position; i < L->size - 1; i++) {
        L->array[i] = L->array[i + 1];
    }
    L->size--;
    printf("삭제 완료. 데이터 이동 횟수: %d\n", L->size - position);
}

int main() {
    ArrayListType list;
    list.size = 0;
    int choice, position;
    element value;

    while (1) {
        printf("\n메뉴:\n");
        printf("1. 리스트에 추가\n");
        printf("2. 리스트에서 삭제\n");
        printf("3. 리스트 출력\n");
        printf("0. 프로그램 종료\n");
        printf("선택: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            if (is_full(&list)) {
                printf("리스트가 꽉 찼습니다.\n");
            }
            else {
                printf("숫자를 입력하세요: ");
                scanf_s("%d", &value);
                printf("추가할 위치를 입력하세요: ", list.size);
                scanf_s("%d", &position);
                insert(&list, position, value);
            }
            break;

        case 2:
            if (is_empty(&list)) {
                printf("리스트가 비어있습니다.\n");
            }
            else {
                printf("삭제할 위치를 입력하세요: ", list.size - 1);
                scanf_s("%d", &position);
                delete(&list, position);
            }
            break;

        case 3:
            print_list(&list);
            break;

        case 0:
            printf("프로그램 종료\n");
            return 0;

        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}