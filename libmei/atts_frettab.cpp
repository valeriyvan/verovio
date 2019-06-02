/////////////////////////////////////////////////////////////////////////////
// Authors:     Laurent Pugin and Rodolfo Zitellini
// Created:     2014
// Copyright (c) Authors and others. All rights reserved.
//
// Code generated using a modified version of libmei
// by Andrew Hankinson, Alastair Porter, and Others
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// NOTE: this file was generated with the Verovio libmei version and
// should not be edited because changes will be lost.
/////////////////////////////////////////////////////////////////////////////

#include "atts_frettab.h"

//----------------------------------------------------------------------------

#include <assert.h>

//----------------------------------------------------------------------------

#include "object.h"

/* #include_block */

namespace vrv {

//----------------------------------------------------------------------------
// AttNoteGesTab
//----------------------------------------------------------------------------

AttNoteGesTab::AttNoteGesTab() : Att()
{
    ResetNoteGesTab();
}

AttNoteGesTab::~AttNoteGesTab()
{
}

void AttNoteGesTab::ResetNoteGesTab()
{
    m_tabCourse = 0;
    m_tabFret = 0;
}

bool AttNoteGesTab::ReadNoteGesTab(pugi::xml_node element)
{
    bool hasAttribute = false;
    if (element.attribute("tab.course")) {
        this->SetTabCourse(StrToInt(element.attribute("tab.course").value()));
        element.remove_attribute("tab.course");
        hasAttribute = true;
    }
    if (element.attribute("tab.fret")) {
        this->SetTabFret(StrToInt(element.attribute("tab.fret").value()));
        element.remove_attribute("tab.fret");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttNoteGesTab::WriteNoteGesTab(pugi::xml_node element)
{
    bool wroteAttribute = false;
    if (this->HasTabCourse()) {
        element.append_attribute("tab.course") = IntToStr(this->GetTabCourse()).c_str();
        wroteAttribute = true;
    }
    if (this->HasTabFret()) {
        element.append_attribute("tab.fret") = IntToStr(this->GetTabFret()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttNoteGesTab::HasTabCourse() const
{
    return (m_tabCourse != 0);
}

bool AttNoteGesTab::HasTabFret() const
{
    return (m_tabFret != 0);
}

/* include <atttab.fret> */

bool Att::SetFrettab(Object *element, std::string attrType, std::string attrValue)
{
    if (element->HasAttClass(ATT_NOTEGESTAB)) {
        AttNoteGesTab *att = dynamic_cast<AttNoteGesTab *>(element);
        assert(att);
        if (attrType == "tab.course") {
            att->SetTabCourse(att->StrToInt(attrValue));
            return true;
        }
        if (attrType == "tab.fret") {
            att->SetTabFret(att->StrToInt(attrValue));
            return true;
        }
    }

    return false;
}

void Att::GetFrettab(const Object *element, ArrayOfStrAttr *attributes)
{
    if (element->HasAttClass(ATT_NOTEGESTAB)) {
        const AttNoteGesTab *att = dynamic_cast<const AttNoteGesTab *>(element);
        assert(att);
        if (att->HasTabCourse()) {
            attributes->push_back(std::make_pair("tab.course", att->IntToStr(att->GetTabCourse())));
        }
        if (att->HasTabFret()) {
            attributes->push_back(std::make_pair("tab.fret", att->IntToStr(att->GetTabFret())));
        }
    }
}

} // vrv namespace