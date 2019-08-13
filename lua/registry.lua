print("registry.lua: start")

-- class.lua
-- Compatible with Lua 5.1 (not 5.0).
function class(base, init)

   local c = {}    -- a new class instance

   if not init and type(base) == 'function' then
      init = base
      base = nil

   elseif type(base) == 'table' then

    -- our new class is a shallow copy of the base class!
      for i,v in pairs(base) do
         c[i] = v
      end
      c._base = base

   end

   -- the class will be the metatable for all its objects,
   -- and they will look up their methods in it.
   c.__index = c

   -- expose a constructor which can be called by <classname>(<args>)
   local mt = {}
   mt.__call = function(class_tbl, ...)
   local obj = {}
   setmetatable(obj,c)

   -- if init then
   --    init(obj,...)
   if class_tbl.init then
      class_tbl.init(obj,...)
   else 
      -- make sure that any stuff from the base class is initialized!
      if base and base.init then
      base.init(obj, ...)
      end
   end
   return obj
   end
   c.init = init
   c.is_a = function(self, klass)
      local m = getmetatable(self)
      while m do 
         if m == klass then return true end
         m = m._base
      end
      return false
   end
   setmetatable(c, mt)
   return c
end


LuaNode = class()
function LuaNode:onInit(node)
    print('LuaNode:onInit()')
end


-- Registry table where all nodes are stored
registry = {
    -- each node is a pair (name, value) where value
    -- is an instance of 
    nodes = {}
}

function registerNode(name, prototype)
    registry.nodes[name] = prototype
end

function initNode(name, node)
    print("initNode(): node name: ".. name)
    -- print("initNode(): functionName: ".. node.functionName)
    
    -- creates an instance of the prototype class
    obj = registry.nodes[name]()
    -- print(node.functionName)
    obj:onInit(node)

    print("initNode(): finish")
end


-- RGBA2gray = class(LuaNode)
-- function RGBA2gray:onInit()
--     print('RGBA2gray:onInit()')
-- end

-- -- register the class
-- registerNode('RGBA2gray', RGBA2gray)

-- obj = registry.nodes['RGBA2gray']()
-- obj:onInit()

print("registry.lua: finish")
