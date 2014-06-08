/*
 * Tests for the lib_xlsx_writer library.
 *
 * Copyright 2014, John McNamara, jmcnamara@cpan.org
 *
 */

#include <gtest/gtest.h>
#include "../helper.h"

#include "xlsxwriter/workbook.h"

// Test the _write_sheet() function.
TEST(workbook, write_sheet1) {


    char* got;
    char exp[] = "<sheet name=\"Sheet1\" sheetId=\"1\" r:id=\"rId1\"/>";
    FILE* testfile = tmpfile();

    lxw_workbook *workbook = new_workbook(NULL);
    workbook->file = testfile;

    _write_sheet(workbook, "Sheet1", 1, 0);

    RUN_XLSX_STREQ(exp, got);

    _free_workbook(workbook);
}

// Test the _write_sheet() function.
TEST(workbook, write_sheet2) {


    char* got;
    char exp[] = "<sheet name=\"Sheet1\" sheetId=\"1\" state=\"hidden\" r:id=\"rId1\"/>";
    FILE* testfile = tmpfile();

    lxw_workbook *workbook = new_workbook(NULL);
    workbook->file = testfile;

    _write_sheet(workbook, "Sheet1", 1, 1);

    RUN_XLSX_STREQ(exp, got);

    _free_workbook(workbook);
}

// Test the _write_sheet() function.
TEST(workbook, write_sheet3) {


    char* got;
    char exp[] = "<sheet name=\"Bits &amp; Bobs\" sheetId=\"1\" r:id=\"rId1\"/>";
    FILE* testfile = tmpfile();

    lxw_workbook *workbook = new_workbook(NULL);
    workbook->file = testfile;

    _write_sheet(workbook, "Bits & Bobs", 1, 0);

    RUN_XLSX_STREQ(exp, got);

    _free_workbook(workbook);
}

