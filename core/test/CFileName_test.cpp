// EXCEPT WHERE OTHERWISE STATED, THE INFORMATION AND SOURCE CODE CONTAINED
// HEREIN AND IN RELATED FILES IS THE EXCLUSIVE PROPERTY OF PARAGON SOFTWARE
// GROUP COMPANY AND MAY NOT BE EXAMINED, DISTRIBUTED, DISCLOSED, OR REPRODUCED
// IN WHOLE OR IN PART WITHOUT EXPLICIT WRITTEN AUTHORIZATION FROM THE COMPANY.
//
// Copyright (c) 1994-2016 Paragon Software Group, All rights reserved.
//
// UNLESS OTHERWISE AGREED IN A WRITING SIGNED BY THE PARTIES, THIS SOFTWARE IS
// PROVIDED "AS-IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
// PARTICULAR PURPOSE, ALL OF WHICH ARE HEREBY DISCLAIMED. IN NO EVENT SHALL THE
// AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF NOT ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.

#include <imageanalyzer/core/CFileName.hpp>

#include <gtest/gtest.h>

//--------------------------------------------------
using namespace imageanalyzer::core;

class CFileName_test
    :public ::testing::Test
{
public:
    void SetUp()
    {}
};

TEST_F(CFileName_test, GetName_only)
{
    CFileName lFileName("name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetName().c_str(), "name");
}

TEST_F(CFileName_test, GetExtension_exist)
{
    CFileName lFileName("name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetExtension().c_str(), "txt");
}

TEST_F(CFileName_test, GetExtension_non)
{
    CFileName lFileName("name");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetExtension().c_str(), "");
}

TEST_F(CFileName_test, GetFileName)
{
    CFileName lFileName("name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetFileName().c_str(), "name.txt");
}

TEST_F(CFileName_test, GetFileName_with_path_win)
{
    CFileName lFileName("path1\\path2\\name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetFileName().c_str(), "name.txt");
}

TEST_F(CFileName_test, GetFileName_with_path_linux)
{
    CFileName lFileName("path1/path2/name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetFileName().c_str(), "name.txt");
}

TEST_F(CFileName_test, GetFileName_with_path_mix_1)
{
    CFileName lFileName("path1/path2\\name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetFileName().c_str(), "name.txt");
}

TEST_F(CFileName_test, GetFileName_with_path_mix_2)
{
    CFileName lFileName("path1\\path2/name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetFileName().c_str(), "name.txt");
}

TEST_F(CFileName_test, GetPath)
{
    CFileName lFileName("name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetPath().ToString().c_str(), "");
}

TEST_F(CFileName_test, GetPath_with_path_win)
{
    CFileName lFileName("path1\\path2\\name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetPath().ToString().c_str(), "path1/path2");
}

TEST_F(CFileName_test, GetPath_with_path_linux)
{
    CFileName lFileName("path1/path2/name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetPath().ToString().c_str(), "path1/path2");
}

TEST_F(CFileName_test, GetPath_with_path_mix_1)
{
    CFileName lFileName("path1/path2\\name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetPath().ToString().c_str(), "path1/path2");
}

TEST_F(CFileName_test, GetPath_with_path_mix_2)
{
    CFileName lFileName("path1\\path2/name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetPath().ToString().c_str(), "path1/path2");
}

TEST_F(CFileName_test, GetFullFileName_only_name)
{
    CFileName lFileName("name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "name.txt");
}

TEST_F(CFileName_test, GetFullFileName_full_one_1)
{
    CFileName lFileName("path1\\path2\\name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\name.txt");
}

TEST_F(CFileName_test, GetFullFileName_full_one_2)
{
    CFileName lFileName("path1\\path2/name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2/name.txt");
}

TEST_F(CFileName_test, GetFullFileName_full_win)
{
    CFileName lFileName(imageanalyzer::core::CPathName("path1\\path2"), "name.txt");
    lFileName.SetSeparator("\\");
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\name.txt");
}

TEST_F(CFileName_test, GetFullFileName_full_linux)
{
    CFileName lFileName(imageanalyzer::core::CPathName("path1/path2"), "name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1/path2/name.txt");
}

TEST_F(CFileName_test, GetFullFileName_full_mix)
{
    CFileName lFileName(imageanalyzer::core::CPathName("path0/path1\\path2"), "name.txt");
    lFileName.SetSeparator("/");
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path0/path1/path2/name.txt");
}

TEST_F(CFileName_test, GetFullFileName_excess_sep1)
{
    CFileName lFileName(imageanalyzer::core::CPathName("path1\\path2\\"), "/filename.exe");
    lFileName.SetSeparator("\\");
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\filename.exe");
}

TEST_F(CFileName_test, GetFullFileName_excess_sep2)
{
    CFileName lFileName(imageanalyzer::core::CPathName("path1\\path2\\\\"), "////filename.exe");
    lFileName.SetSeparator("\\");
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\filename.exe");
}

TEST_F(CFileName_test, GetFullFileName_excess_sep3)
{
    CFileName lFileName(imageanalyzer::core::CPathName("path1\\path2\\/\\"), "////filename.exe");
    lFileName.SetSeparator("\\");
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\filename.exe");
}

TEST_F(CFileName_test, GetFullFileName_excess_sep4)
{
    CFileName lFileName(imageanalyzer::core::CPathName("path1\\path2"), "filename.exe");
    lFileName.SetSeparator("\\");
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\filename.exe");
}

TEST_F(CFileName_test, AddPath1)
{
    CFileName lFileName(imageanalyzer::core::CPathName("path1\\path2"), "filename.exe");
    lFileName.SetSeparator("\\");
    lFileName.AddPath(imageanalyzer::core::CPathName("path3"));
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\path3\\filename.exe");
}

TEST_F(CFileName_test, AddPath2)
{
    CFileName lFileName(imageanalyzer::core::CPathName("path1\\path2"), "filename.exe");
    lFileName.SetSeparator("\\");
    lFileName.AddPath(imageanalyzer::core::CPathName("\\path3"));
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\path3\\filename.exe");
}

TEST_F(CFileName_test, AddPath3)
{
    CFileName lFileName(imageanalyzer::core::CPathName("path1\\path2"), "filename.exe");
    lFileName.SetSeparator("\\");
    lFileName.AddPath(imageanalyzer::core::CPathName("path3\\"));
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\path3\\filename.exe");
}

TEST_F(CFileName_test, AddPath4)
{
    CFileName lFileName(imageanalyzer::core::CPathName("path1\\path2"), "filename.exe");
    lFileName.SetSeparator("\\");
    lFileName.AddPath(imageanalyzer::core::CPathName("\\path3\\"));
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\path3\\filename.exe");
}

TEST_F(CFileName_test, AddPath5)
{
    CFileName lFileName(imageanalyzer::core::CPathName("path1\\path2"), "filename.exe");
    lFileName.SetSeparator("\\");
    lFileName.AddPath(imageanalyzer::core::CPathName("\\path3\\/\\"));
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\path3\\filename.exe");
}

TEST_F(CFileName_test, AddPath6)
{
    CFileName lFileName(imageanalyzer::core::CPathName("path1\\path2"), "filename.exe");
    lFileName.SetSeparator("\\");
    lFileName.AddPath(imageanalyzer::core::CPathName("\\/\\path3\\/\\"));
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\path3\\filename.exe");
}

TEST_F(CFileName_test, AddPath_only_path)
{
    CFileName lFileName("path1\\path2\\");
    lFileName.SetSeparator("\\");
    lFileName.AddPath(imageanalyzer::core::CPathName("\\/\\path3\\/\\"));
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\path3\\");
}

TEST_F(CFileName_test, AddFileName1)
{
    CFileName lFileName("path1\\path2\\");
    lFileName.SetSeparator("\\");
    lFileName.AddFileName(CFileName(imageanalyzer::core::CPathName("\\/\\path3\\/\\"), ""));
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\path3\\");
}

TEST_F(CFileName_test, AddFileName2)
{
    CFileName lFileName("path1\\path2\\test.c");
    lFileName.SetSeparator("\\");
    lFileName.AddFileName(CFileName(imageanalyzer::core::CPathName("\\/\\path3\\/\\"), "new_test.c"));
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\path3\\new_test.c");
}

TEST_F(CFileName_test, AddFileName3)
{
    CFileName lFileName("path1\\path2\\test.c");
    lFileName.SetSeparator("\\");
    lFileName.AddFileName(CFileName("\\/\\path3\\/\\new_test.c"));
    ASSERT_STREQ(lFileName.GetFullFileName().c_str(), "path1\\path2\\path3\\new_test.c");
}