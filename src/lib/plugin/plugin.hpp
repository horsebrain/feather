/***********************************************************************
 *
 * Filename: plugin.hpp
 *
 * Description: Gives plugins functions easy access to scenegraph data.
 *
 * Copyright (C) 2016 Richard Layman, rlayman2000@yahoo.com 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ***********************************************************************/

#ifndef PLUGIN_HPP
#define PLUGIN_HPP

#include "deps.hpp"
#include "types.hpp"

namespace feather
{
    namespace plugin
    {
        // clear scenegraph
        void clear();

        // get the low uid value
        unsigned int get_min_uid();

        // get the highest uid value
        unsigned int get_max_uid();

        // is uid already in scenegraph
        bool node_exist(unsigned int uid);

        // add a node to the scenegraph
        unsigned int add_node(unsigned int nid, std::string name, status& error);

        // remove node from scenegraph
        void remove_node(unsigned int uid, status& error);

        // get a list of all nodes connected to this node's out fields
        void get_node_out_connections(unsigned int uid, std::vector<unsigned int>& uids); 

        // get all the nodes in the scenegraph
        void get_nodes(std::vector<unsigned int>& uids);

        // get uid of node by it's name
        void get_node_by_name(std::string name, unsigned int& uid);

        // get all nodes of a certain type
        void get_node_by_type(node::Type type, std::vector<unsigned int>& uids);

        // get node name
        void get_node_name(unsigned int uid, std::string& name, status& error);

        // get node icon 
        void get_node_icon(unsigned int nid, std::string& file, status& error);

        // get node id
        unsigned int get_node_id(unsigned int uid, status& error);

        // get all nodes connected to uid
        status get_node_connected_uids(unsigned int uid, std::vector<int>& uids);

        // get all nodes connected to fid
        status get_node_connected_uids(unsigned int uid, unsigned int fid, std::vector<int>& uids);

        // FIELD DATA
        
        // get field base
        // returns the fieldBase* for the node's fid - if the fid is connected, it will return the fieldBase* of the node that's connected to it.
        field::FieldBase* get_field_base(unsigned int uid, unsigned int nid, unsigned int fid);

        // same as above without the nid
        field::FieldBase* get_field_base(unsigned int uid, unsigned int fid);

        // get field base
        // returns the fieldBase* for the node's fid even if it's connected
        field::FieldBase* get_node_field_base(unsigned int uid, unsigned int nid, unsigned int fid);

        // same as above without the nid
        field::FieldBase* get_node_field_base(unsigned int uid, unsigned int fid);


    }

}

#endif
