descriptor = {
    inputs = {
        RGBA = {
            type = 'ImageView',
        }
    },
    outputs = {
        gray = {
            type = 'ImageView'
        }
    },
    spirv = 'AwIjBwAAAQACAA0AIAAAAAAAAAARAAIAAQAAAAsABgABAAAAR0x'..
            'TTC5zdGQuNDUwAAAAAA4AAwAAAAAAAQAAAA8ABgAFAAAABAAAAG'..
            '1haW4AAAAACwAAABAABgAEAAAAEQAAAAEAAAABAAAAAQAAAAMAA'..
            'wACAAAAwgEAAAQACgBHTF9HT09HTEVfY3BwX3N0eWxlX2xpbmVf'..
            'ZGlyZWN0aXZlAAAEAAgAR0xfR09PR0xFX2luY2x1ZGVfZGlyZWN'..
            '0aXZlAAUABAAEAAAAbWFpbgAAAAAFAAQACAAAAGluZGV4AAAABQ'..
            'AIAAsAAABnbF9HbG9iYWxJbnZvY2F0aW9uSUQAAAAFAAQAEgAAA'..
            'G91dDAAAAAABgAHABIAAAAAAAAAb3V0cHV0QnVmZmVyAAAAAAUA'..
            'AwAUAAAAAAAAAEcABAALAAAACwAAABwAAABHAAQAEQAAAAYAAAA'..
            'EAAAASAAFABIAAAAAAAAAIwAAAAAAAABHAAMAEgAAAAMAAABHAA'..
            'QAFAAAACIAAAAAAAAARwAEABQAAAAhAAAAAAAAAEcABAAcAAAAA'..
            'QAAAAEAAABHAAQAHQAAAAEAAAACAAAARwAEAB4AAAABAAAAAwAA'..
            'AEcABAAfAAAACwAAABkAAAATAAIAAgAAACEAAwADAAAAAgAAABU'..
            'ABAAGAAAAIAAAAAAAAAAgAAQABwAAAAcAAAAGAAAAFwAEAAkAAA'..
            'AGAAAAAwAAACAABAAKAAAAAQAAAAkAAAA7AAQACgAAAAsAAAABA'..
            'AAAKwAEAAYAAAAMAAAAAAAAACAABAANAAAAAQAAAAYAAAAWAAMA'..
            'EAAAACAAAAAdAAMAEQAAABAAAAAeAAMAEgAAABEAAAAgAAQAEwA'..
            'AAAIAAAASAAAAOwAEABMAAAAUAAAAAgAAABUABAAVAAAAIAAAAA'..
            'EAAAArAAQAFQAAABYAAAAAAAAAIAAEABoAAAACAAAAEAAAADIAB'..
            'AAGAAAAHAAAAAEAAAAyAAQABgAAAB0AAAABAAAAMgAEAAYAAAAe'..
            'AAAAAQAAADMABgAJAAAAHwAAABwAAAAdAAAAHgAAADYABQACAAA'..
            'ABAAAAAAAAAADAAAA+AACAAUAAAA7AAQABwAAAAgAAAAHAAAAQQ'..
            'AFAA0AAAAOAAAACwAAAAwAAAA9AAQABgAAAA8AAAAOAAAAPgADA'..
            'AgAAAAPAAAAPQAEAAYAAAAXAAAACAAAAD0ABAAGAAAAGAAAAAgA'..
            'AABwAAQAEAAAABkAAAAYAAAAQQAGABoAAAAbAAAAFAAAABYAAAA'..
            'XAAAAPgADABsAAAAZAAAA/QABADgAAQA='
}

function on_init(node)

    -- this is assumed to be initalized by lluvia
    RGBA = node.inputs.RGBA
    RGBA.shape = {640, 480, 4}
    RGBA.channelType = 'uint8'

    -- Initialize the output
    iShape = node.inputs.RGBA.shape

    gray = {
        type = 'ImageView',
        shape = {iShape[1] / 2, iShape[2] / 2},
        channelCount = 1,
        channelType = RGBA.channelType,
        usageFlags = {'TransferSrc', 'TransferDst'},
        tiling = 'Optimal'
    }
    node.outputs.gray = gray

    -- local size
    node.localSize = {32, 64, 1}


    -- are values copied or referenced?
    -- they are referenced!!!
    -- node.inputs.RGBA.shape[1] = 890
    -- node.outputs.gray.shape[1] = 500

    -- print(node.spirv)
    -- print(node.inputs.RGBA.shape[1])
    print(node.outputs.gray.shape[2])

    -- Return the node descriptor back to lluvia
    -- to instantiate the outputs and further processing
    return node
end

-- out = on_init(desc)
