/*
 * Tests for the lib_xlsx_writer library.
 *
 * Copyright 2014, John McNamara, jmcnamara@cpan.org
 *
 */

#include <gtest/gtest.h>
#include "../helper.h"

#include "xlsxwriter/worksheet.h"

// Test the _write_sheet_views() function.
TEST(worksheet, write_sheet_views) {

    char* got;
    char exp[] = "<sheetViews><sheetView tabSelected=\"1\" workbookViewId=\"0\"/></sheetViews>";
    FILE* testfile = tmpfile();

    lxw_worksheet *worksheet = _new_worksheet(NULL);
    worksheet->file = testfile;
    worksheet->selected = 1;

    _worksheet_write_sheet_views(worksheet);

    RUN_XLSX_STREQ(exp, got);

    _free_worksheet(worksheet);
}

