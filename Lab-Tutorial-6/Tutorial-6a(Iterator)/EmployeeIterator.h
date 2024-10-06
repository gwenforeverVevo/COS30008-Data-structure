class EmployeeIterator
{
private:
    const Employee *fEmpList;
    const int fSize;
    int fIndex;

public:
    EmployeeIterator(const Employee aEmpList[], const int aSize, int aStart = 0);
    const Employee &operator*() const;
    EmployeeIterator &operator++();
    EmployeeIterator &operator++(int);
    bool operator==(const EmployeeIterator &aOther) const;
    bool operator!=(const EmployeeIterator &aOther) const;
    EmployeeIterator begin() const;
    EmployeeIterator end() const;
};