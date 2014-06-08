/*
 * Tests for the lib_xlsx_writer library.
 *
 * Copyright 2014, John McNamara, jmcnamara@cpan.org
 *
 */

#include <gtest/gtest.h>
#include "../helper.h"

#include "xlsxwriter/workbook.h"

// Test the _write_file_version() function.
TEST(workbook, write_file_version) {

    char* got;
    char exp[] = "<fileVersion appName=\"xl\" lastEdited=\"4\" lowestEdited=\"4\" rupBuild=\"4505\"/>";
    FILE* testfile = tmpfile();

    lxw_workbook *workbook = new_workbook(NULL);
    workbook->file = testfile;

    _write_file_version(workbook);

    RUN_XLSX_STREQ(exp, got);

    _free_workbook(workbook);
}

