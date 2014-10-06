/******************************************************************************
 *   Copyright (C) 2013-2014 by Alexander Rykovanov                        *
 *   rykovanov.as@gmail.com                                                   *
 *                                                                            *
 *   This library is free software; you can redistribute it and/or modify     *
 *   it under the terms of the GNU Lesser General Public License as           *
 *   published by the Free Software Foundation; version 3 of the License.     *
 *                                                                            *
 *   This library is distributed in the hope that it will be useful,          *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 *   GNU Lesser General Public License for more details.                      *
 *                                                                            *
 *   You should have received a copy of the GNU Lesser General Public License *
 *   along with this library; if not, write to the                            *
 *   Free Software Foundation, Inc.,                                          *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.                *
 ******************************************************************************/

#pragma once

#include <opc/ua/services/services.h>
#include <opc/ua/model.h>

#include <boost/asio/deadline_timer.hpp>

namespace boost
{
  namespace asio
  {
    class io_service;
  }
}

namespace OpcUa
{
  namespace Server
  {

    class ServerObject
    {
    public:
      DEFINE_CLASS_POINTERS(ServerObject);

    public:
      ServerObject(Services::SharedPtr services, boost::asio::io_service& io);
      ~ServerObject();

    private:
      Model::Object CreateServerObject(const Services::SharedPtr& services) const;
      void OnTimer(const boost::system::error_code& error);

    private:
      Services::SharedPtr Server;
      boost::asio::io_service& Io;
      Model::Object Instance;
      Model::Variable ServerTime;
      boost::asio::deadline_timer Timer;
    };

  }
}