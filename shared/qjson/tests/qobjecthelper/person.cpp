// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "person.h"

Person::Person(QObject* parent)
  : QObject(parent)
  , m_name()
  , m_phoneNumber(0)
  , m_gender(Female)
{
}

Person::~Person()
{
}

QString Person::name() const
{
  return m_name;
}

void Person::setName(const QString& name)
{
  m_name = name;
}

int Person::phoneNumber() const
{
  return m_phoneNumber;
}

void Person::setPhoneNumber(const int phoneNumber)
{
  m_phoneNumber = phoneNumber;
}

void Person::setGender(Gender gender)
{
  m_gender = gender;
}

Person::Gender Person::gender() const
{
  return m_gender;
}

QDate Person::dob() const
{
  return m_dob;
}

void Person::setDob(const QDate& dob)
{
  m_dob = dob;
}

QVariant Person::customField() const
{
  return m_customField;
}

void Person::setCustomField(const QVariant& customField)
{
  m_customField = customField;
}

