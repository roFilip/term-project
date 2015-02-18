#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string.h>

typedef const unsigned int* id_resource;

/**
 * Resource Manager.
 * 
 * Loads files into resources of type T(declared when instantiated).
 * 
 * @author Lewis Scott
 */
template <class T> class ResourceManager
{
	public:
		/**
		* Destructor.
		*/
		~ResourceManager(){ clear(); }
		
		/**
		* Loads a resource from the specified file.
		*
		* @param - std::string path - a qualified path to the desired resource
		* @return - object<T> - The resource that was loaded
		*/
		virtual T load(std::string);
		
		/**
		* Creates an ID for a resource and stores it.
		*
		* @param - object<T> res - The resource to store
		* @return - id_resource - The ID assigned to the resource
		*/
		id_resource store(T);
		
		/**
		* Stores a resource, overwriting the previously stored one.
		*
		* @param - object<T> res - The resource to store
		* @param - id_resource id - The id to store it at
		* @return - void
		*/
		void store(T, id_resource);
		
		/**
		* Gets a resource from a specified ID.
		*
		* @param - id_resource id - The id to fetch
		* @return - object<T> - The resource loaded, or NULL if not found
		*/
		T get(id_resource);
		
		/**
		* Removes a resource from the manager, freeing it's ID.
		*
		* @param - id_resource id - The id of the resource to remove
		* @return - object<T> - The object removed, or NULL if not found
		*/
		T remove(id_resource);
		
		/**
		* Clears the manager of all resources and IDs.
		*
		* @return - unsigned int count - The number of resources purged
		*/
		unsigned int clear();
		
	private:
		unsigned int ID_RESOURCE;
		std::map<id_resource, T> resource_map;
};

#endif // RESOURCE_MANAGER_H