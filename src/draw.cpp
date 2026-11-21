#include "draw.hpp"
#include "termbox2.h"

namespace draw {
void make_square(int x1, int y1, int x2, int y2) {
    for (int i = 0; i < x2 - x1; i++) {
        tb_set_cell(i + x1, y1, 0x2500, TB_GREEN | TB_BOLD, TB_DEFAULT);
        tb_set_cell(i + x1, y2, 0x2500, TB_GREEN | TB_BOLD, TB_DEFAULT);
    }
    for (int i = 0; i < y2 - y1; i++) {
        tb_set_cell(x1, i + y1, 0x2502, TB_GREEN | TB_BOLD, TB_DEFAULT);
        tb_set_cell(x2, i + y1, 0x2502, TB_GREEN | TB_BOLD, TB_DEFAULT);
    }
    tb_set_cell(x1, y1, 0x256D, TB_GREEN | TB_BOLD, TB_DEFAULT);
    tb_set_cell(x2, y1, 0x256E, TB_GREEN | TB_BOLD, TB_DEFAULT);
    tb_set_cell(x1, y2, 0x2570, TB_GREEN | TB_BOLD, TB_DEFAULT);
    tb_set_cell(x2, y2, 0x256f, TB_GREEN | TB_BOLD, TB_DEFAULT);
}
} // namespace draw
