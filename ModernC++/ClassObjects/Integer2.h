#pragma once

class Integer2 {
    int m_Value{ 0 };
public:
    Integer2() = default;
    /*Integer2() {
        m_Value = 0;
    }*/
    Integer2(int value)
    {
        m_Value = value;
    }
    Integer2(const Integer2&) = delete;
    void SetValue(int value)
    {
        m_Value = value;
    }

    void SetValue(float) = delete;
};