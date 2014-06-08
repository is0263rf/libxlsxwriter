/*****************************************************************************
 * Test cases for libxlsxwriter.
 *
 * Simple test case to test data writing.
 *
 * Copyright 2014, John McNamara, jmcnamara@cpan.org
 *
 */

#include "xlsxwriter.h"

/* Ignore warnings about unused variables since this file is testing how
 * unused formats are handled.
 */
#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {

    lxw_workbook  *workbook  = new_workbook("test_format01.xlsx");
    lxw_worksheet *worksheet1 = workbook_add_worksheet(workbook, NULL);
    lxw_worksheet *worksheet2 = workbook_add_worksheet(workbook, "Data Sheet");
    lxw_worksheet *worksheet3 = workbook_add_worksheet(workbook, NULL);

    lxw_format    *unused1    = workbook_add_format(workbook);
    lxw_format    *format     = workbook_add_format(workbook);
    lxw_format    *unused2    = workbook_add_format(workbook);
    lxw_format    *unused3    = workbook_add_format(workbook);

    format_set_bold(format);

    worksheet_write_string(worksheet1, 0, 0, "Foo", NULL);
    worksheet_write_number(worksheet1, 1, 0, 123, NULL);

    worksheet_write_string(worksheet3, 1, 1, "Foo", NULL);
    worksheet_write_string(worksheet3, 2, 1, "Bar", format);
    worksheet_write_number(worksheet3, 3, 2, 234, NULL);

    return workbook_close(workbook);
}
