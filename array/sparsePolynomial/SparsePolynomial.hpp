struct Term
{
    float coef;
    int exp;
};

class SparsePolynomial
{
public:
    SparsePolynomial()
    {
    }

    SparsePolynomial(const SparsePolynomial& other);

    ~SparsePolynomial();

    // 새로운 항을 추가할 때 자기 위치를 찾아서 넣어줘야 함
    void NewTerm(float coef, int exp);

    float Eval(float x);

    SparsePolynomial Add(const SparsePolynomial& poly);

    void Print();

private:
    Term* terms_ = nullptr;
    int capacity_ = 0;
    int num_terms_ = 0;
};