/*
 * Copyright (C) 2009 Toni Gundogdu.
 *
 * This file is part of cclive.
 * 
 * cclive is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 * 
 * cclive is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string>
#include <sstream>

#include "except.h"
#include "video.h"
#include "curl.h"
#include "log.h"
#include "opts.h"
#include "retry.h"

RetryMgr::RetryMgr()
    : retries(0)
{
}

void
RetryMgr::reset() {
    retries = 0;
}

void
RetryMgr::handle(const CurlMgr::FetchException& x) {

    logmgr.cerr(x);

    switch ( x.getHTTPCode() ) {

    case 403: // Forbidden
    case 404: // Not found
        break;

    default:
        const Options opts =
            optsmgr.getOptions();

        if (++retries <= opts.retry_arg) {
            logmgr.cout()
                << "retry #"
                << retries
                << " ..."
                << std::endl;
        }
        else
            throw x;
    }
}
