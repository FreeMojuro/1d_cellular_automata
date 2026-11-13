#pragma once
#include <raylib.h>
#include <memory>
#include <array>

constexpr int window_width{1500};
constexpr int window_height{900};
constexpr int cell_size{5};
constexpr int num_presets{8};
inline int current_preset{0};

struct Cell{
    int state;
    Vector2 pos;
};


inline void Rule110(int i, const Cell& left, const Cell& current, const Cell& right, std::unique_ptr<std::array<Cell, window_width/cell_size>>& new_neighborhood){
    Cell& new_c{new_neighborhood->at(i)};

    if(left.state == 1 && current.state == 1 && right.state == 1)new_c.state = 0;
    else if(left.state == 1 && current.state == 1 && right.state == 0)new_c.state = 1;
    else if(left.state == 1 && current.state == 0 && right.state == 1)new_c.state = 1;
    else if(left.state == 1 && current.state == 0 && right.state == 0)new_c.state = 0;
    else if(left.state == 0 && current.state == 1 && right.state == 1)new_c.state = 1;
    else if(left.state == 0 && current.state == 1 && right.state == 0)new_c.state = 1;
    else if(left.state == 0 && current.state == 0 && right.state == 1)new_c.state = 1;
    else if(left.state == 0 && current.state == 0 && right.state == 0)new_c.state = 0;
}

inline void Rule90(int i, const Cell& left, const Cell& current, const Cell& right, std::unique_ptr<std::array<Cell, window_width/cell_size>>& new_neighborhood){
    Cell& new_c{new_neighborhood->at(i)};

    if(left.state == 1 && current.state == 1 && right.state == 1)new_c.state = 0;
    else if(left.state == 1 && current.state == 1 && right.state == 0)new_c.state = 1;
    else if(left.state == 1 && current.state == 0 && right.state == 1)new_c.state = 0;
    else if(left.state == 1 && current.state == 0 && right.state == 0)new_c.state = 1;
    else if(left.state == 0 && current.state == 1 && right.state == 1)new_c.state = 1;
    else if(left.state == 0 && current.state == 1 && right.state == 0)new_c.state = 0;
    else if(left.state == 0 && current.state == 0 && right.state == 1)new_c.state = 1;
    else if(left.state == 0 && current.state == 0 && right.state == 0)new_c.state = 0;
}

inline void Rule30(int i, const Cell& left, const Cell& current, const Cell& right, std::unique_ptr<std::array<Cell, window_width/cell_size>>& new_neighborhood){
    Cell& new_c{new_neighborhood->at(i)};

    if(left.state == 1 && current.state == 1 && right.state == 1)new_c.state = 0;
    else if(left.state == 1 && current.state == 1 && right.state == 0)new_c.state = 0;
    else if(left.state == 1 && current.state == 0 && right.state == 1)new_c.state = 0;
    else if(left.state == 1 && current.state == 0 && right.state == 0)new_c.state = 1;
    else if(left.state == 0 && current.state == 1 && right.state == 1)new_c.state = 1;
    else if(left.state == 0 && current.state == 1 && right.state == 0)new_c.state = 1;
    else if(left.state == 0 && current.state == 0 && right.state == 1)new_c.state = 1;
    else if(left.state == 0 && current.state == 0 && right.state == 0)new_c.state = 0;
}

inline void Rule18(int i, const Cell& left, const Cell& current, const Cell& right, std::unique_ptr<std::array<Cell, window_width/cell_size>>& new_neighborhood){
    Cell& new_c{new_neighborhood->at(i)};

    if(left.state == 1 && current.state == 1 && right.state == 1)new_c.state = 0;
    else if(left.state == 1 && current.state == 1 && right.state == 0)new_c.state = 0;
    else if(left.state == 1 && current.state == 0 && right.state == 1)new_c.state = 0;
    else if(left.state == 1 && current.state == 0 && right.state == 0)new_c.state = 1;
    else if(left.state == 0 && current.state == 1 && right.state == 1)new_c.state = 0;
    else if(left.state == 0 && current.state == 1 && right.state == 0)new_c.state = 0;
    else if(left.state == 0 && current.state == 0 && right.state == 1)new_c.state = 1;
    else if(left.state == 0 && current.state == 0 && right.state == 0)new_c.state = 0;
}

inline void Rule22(int i, const Cell& left, const Cell& current, const Cell& right, std::unique_ptr<std::array<Cell, window_width/cell_size>>& new_neighborhood){
    Cell& new_c{new_neighborhood->at(i)};

    if(left.state == 1 && current.state == 1 && right.state == 1)new_c.state = 0;
    else if(left.state == 1 && current.state == 1 && right.state == 0)new_c.state = 0;
    else if(left.state == 1 && current.state == 0 && right.state == 1)new_c.state = 0;
    else if(left.state == 1 && current.state == 0 && right.state == 0)new_c.state = 1;
    else if(left.state == 0 && current.state == 1 && right.state == 1)new_c.state = 0;
    else if(left.state == 0 && current.state == 1 && right.state == 0)new_c.state = 1;
    else if(left.state == 0 && current.state == 0 && right.state == 1)new_c.state = 1;
    else if(left.state == 0 && current.state == 0 && right.state == 0)new_c.state = 0;
}

inline void Rule54(int i, const Cell& left, const Cell& current, const Cell& right, std::unique_ptr<std::array<Cell, window_width/cell_size>>& new_neighborhood){
    Cell& new_c{new_neighborhood->at(i)};

    if(left.state == 1 && current.state == 1 && right.state == 1)new_c.state = 0;
    else if(left.state == 1 && current.state == 1 && right.state == 0)new_c.state = 0;
    else if(left.state == 1 && current.state == 0 && right.state == 1)new_c.state = 1;
    else if(left.state == 1 && current.state == 0 && right.state == 0)new_c.state = 1;
    else if(left.state == 0 && current.state == 1 && right.state == 1)new_c.state = 0;
    else if(left.state == 0 && current.state == 1 && right.state == 0)new_c.state = 1;
    else if(left.state == 0 && current.state == 0 && right.state == 1)new_c.state = 1;
    else if(left.state == 0 && current.state == 0 && right.state == 0)new_c.state = 0;
}

inline void Rule150(int i, const Cell& left, const Cell& current, const Cell& right, std::unique_ptr<std::array<Cell, window_width/cell_size>>& new_neighborhood){
    Cell& new_c{new_neighborhood->at(i)};

    if(left.state == 1 && current.state == 1 && right.state == 1)new_c.state = 1;
    else if(left.state == 1 && current.state == 1 && right.state == 0)new_c.state = 0;
    else if(left.state == 1 && current.state == 0 && right.state == 1)new_c.state = 0;
    else if(left.state == 1 && current.state == 0 && right.state == 0)new_c.state = 1;
    else if(left.state == 0 && current.state == 1 && right.state == 1)new_c.state = 0;
    else if(left.state == 0 && current.state == 1 && right.state == 0)new_c.state = 1;
    else if(left.state == 0 && current.state == 0 && right.state == 1)new_c.state = 1;
    else if(left.state == 0 && current.state == 0 && right.state == 0)new_c.state = 0;
}

inline void Rule184(int i, const Cell& left, const Cell& current, const Cell& right, std::unique_ptr<std::array<Cell, window_width/cell_size>>& new_neighborhood){
    Cell& new_c{new_neighborhood->at(i)};

    if(left.state == 1 && current.state == 1 && right.state == 1)new_c.state = 1;
    else if(left.state == 1 && current.state == 1 && right.state == 0)new_c.state = 0;
    else if(left.state == 1 && current.state == 0 && right.state == 1)new_c.state = 1;
    else if(left.state == 1 && current.state == 0 && right.state == 0)new_c.state = 1;
    else if(left.state == 0 && current.state == 1 && right.state == 1)new_c.state = 1;
    else if(left.state == 0 && current.state == 1 && right.state == 0)new_c.state = 0;
    else if(left.state == 0 && current.state == 0 && right.state == 1)new_c.state = 0;
    else if(left.state == 0 && current.state == 0 && right.state == 0)new_c.state = 0;
}

inline void Check(int i, const Cell& left, const Cell& current, const Cell& right, std::unique_ptr<std::array<Cell, window_width/cell_size>>& new_neighborhood){
    if(current_preset == 0)Rule110(i,left,current,right,new_neighborhood);
    else if(current_preset == 1)Rule90(i,left,current,right,new_neighborhood);
    else if(current_preset == 2)Rule30(i,left,current,right,new_neighborhood);
    else if(current_preset == 3)Rule18(i,left,current,right,new_neighborhood);
    else if(current_preset == 4)Rule22(i,left,current,right,new_neighborhood);
    else if(current_preset == 5)Rule54(i,left,current,right,new_neighborhood);
    else if(current_preset == 6)Rule150(i,left,current,right,new_neighborhood);
    else if(current_preset == 7)Rule184(i,left,current,right,new_neighborhood);

}
