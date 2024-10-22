

void alterarPonteiroValor(int* ptr) {
    int b = 20;

    *ptr = 90;

    ptr = &b; // Isso altera apenas a cópia de ptr, não o original

    *ptr = 100;


}

int main() {
    int a = 10;
    int* p = &a; // p aponta para 'a'

    alterarPonteiroValor(p); // p ainda aponta para 'a' após a função
}