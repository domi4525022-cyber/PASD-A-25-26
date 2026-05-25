#include <iostream>
using namespace std;

typedef struct node *alamatnode;

typedef struct node {
    char INFO;
    alamatnode RIGHT;
    alamatnode LEFT;
} NODE;

typedef struct {
    NODE *root;
} TREE;

void BuatTree(char C, TREE *T) {
    NODE *Baru;

    Baru = new NODE;
    Baru->INFO = C;
    Baru->RIGHT = NULL;
    Baru->LEFT = NULL;

    (*T).root = Baru;
}

void TambahKanan(char C, NODE *root) {
    if (root->RIGHT == NULL) {

        //Apabila sub tree kanan kosong
        NODE *Baru;

        Baru = new NODE;
        Baru->INFO = C;
        Baru->RIGHT = NULL;
        Baru->LEFT = NULL;

        root->RIGHT = Baru;
    }
    else
        cout << "Sub Tree Kanan telah diisi" << endl;
}

void TambahKiri(char C, NODE *root) {
    if (root->LEFT == NULL) {

        //Apabila sub tree kiri kosong
        NODE *Baru;

        Baru = new NODE;
        Baru->INFO = C;
        Baru->RIGHT = NULL;
        Baru->LEFT = NULL;

        root->LEFT = Baru;
    }
    else
        cout << "Sub Tree Kiri telah diisi" << endl;
}

void CetakTreePreOrder(NODE *root) {
    if (root != NULL) {
        cout << root->INFO << " ";
        CetakTreePreOrder(root->LEFT);
        CetakTreePreOrder(root->RIGHT);
    }
}

void CetakTreeInOrder(NODE *root) {
    if (root != NULL) {
        CetakTreeInOrder(root->LEFT);
        cout << root->INFO << " ";
        CetakTreeInOrder(root->RIGHT);
    }
}

void CetakTreePostOrder(NODE *root) {
    if (root != NULL) {
        CetakTreePostOrder(root->LEFT);
        CetakTreePostOrder(root->RIGHT);
        cout << root->INFO << " ";
    }
}

int JumlahNode(NODE *root) {
    if (root == NULL)
        return 0;
    else
        return 1 + JumlahNode(root->LEFT) + JumlahNode(root->RIGHT);
}

int TinggiTree(NODE *root) {
    int kiri, kanan;

    if (root == NULL)
        return 0;
    else {
        kiri = TinggiTree(root->LEFT);
        kanan = TinggiTree(root->RIGHT);

        if (kiri > kanan)
            return kiri + 1;
        else
            return kanan + 1;
    }
}

void CopyTree(NODE *root1, NODE **root2) {
    if (root1 != NULL) {

        (*root2) = new NODE;

        (*root2)->INFO = root1->INFO;
        (*root2)->LEFT = NULL;
        (*root2)->RIGHT = NULL;

        if (root1->LEFT != NULL)
            CopyTree(root1->LEFT, &((*root2)->LEFT));

        if (root1->RIGHT != NULL)
            CopyTree(root1->RIGHT, &((*root2)->RIGHT));
    }
}

bool isEqual(NODE *root1, NODE *root2) {

    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 != NULL && root2 != NULL) {

        return (
            root1->INFO == root2->INFO &&
            isEqual(root1->LEFT, root2->LEFT) &&
            isEqual(root1->RIGHT, root2->RIGHT)
        );
    }

    return false;
}

void TampilLeaf(NODE *root) {
    if (root != NULL) {

        if (root->LEFT == NULL && root->RIGHT == NULL) {
            cout << root->INFO << " ";
        }

        TampilLeaf(root->LEFT);
        TampilLeaf(root->RIGHT);
    }
}

int JumlahLeaf(NODE *root) {

    if (root == NULL)
        return 0;

    if (root->LEFT == NULL && root->RIGHT == NULL)
        return 1;

    return JumlahLeaf(root->LEFT) + JumlahLeaf(root->RIGHT);
}

int main() {

    TREE T;
    TREE Salinan;

    BuatTree('R', &T);

    TambahKiri('S', T.root);
    TambahKanan('U', T.root);

    TambahKiri('V', T.root->LEFT);
    TambahKanan('W', T.root->LEFT);

    TambahKiri('Y', T.root->RIGHT);
    TambahKanan('Z', T.root->RIGHT);

    cout << " ============================== " << endl;
    cout << " ======      PREORDER    ===== " << endl;
    cout << " ============================== " << endl;

    cout << endl;
    CetakTreePreOrder(T.root);
    cout << endl << endl;

    cout << " ============================== " << endl;
    cout << " ======      INORDER     ===== " << endl;
    cout << " ============================== " << endl;

    cout << endl;
    CetakTreeInOrder(T.root);
    cout << endl << endl;

    cout << " ============================== " << endl;
    cout << " ======     POSTORDER    ===== " << endl;
    cout << " ============================== " << endl;

    cout << endl;
    CetakTreePostOrder(T.root);
    cout << endl << endl;

    cout << "Jumlah Node = "
         << JumlahNode(T.root) << endl;

    cout << "Tinggi Tree = "
         << TinggiTree(T.root) << endl;

    cout << "Node Leaf = ";
    TampilLeaf(T.root);
    cout << endl;

    cout << "Jumlah Leaf = "
         << JumlahLeaf(T.root) << endl;

    CopyTree(T.root, &Salinan.root);

    if (isEqual(T.root, Salinan.root))
        cout << "Tree Asli dan Tree Salinan Sama" << endl;
    else
        cout << "Tree Asli dan Tree Salinan Tidak Sama" << endl;

    return 0;
}