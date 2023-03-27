local exports = {}

exports.name = "scenes.game_scene"

function exports.init()
    PPRINT({
        Hellow = "I don't know",
        World = "Initializing intro scene",
    })
end

function exports.update(dt)
end

function exports.draw()
    local x = 400
    local y = 300

    local mx, my = love.mouse.getPosition()
    if mx then
        x = mx
    end
    if my then
        y = my
    end

    local touch_ids = love.touch.getTouches()
    if #touch_ids > 0 then
        local tx, ty = love.touch.getPosition(touch_ids[1])
        if tx then
            x = tx
        end

        if ty then
            y = ty
        end
    end

    love.graphics.rectangle("fill", x-40, y-40, 80, 80)
end

return exports
